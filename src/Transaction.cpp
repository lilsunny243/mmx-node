/*
 * Transaction.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: mad
 */

#include <mmx/Transaction.hxx>
#include <mmx/solution/PubKey.hxx>
#include <mmx/write_bytes.h>


namespace mmx {

hash_t TransactionBase::calc_hash() const {
	return id;
}

uint64_t TransactionBase::calc_cost(std::shared_ptr<const ChainParams> params) const {
	return 0;
}

std::shared_ptr<const TransactionBase> TransactionBase::create_ex(const hash_t& id)
{
	auto tx = TransactionBase::create();
	tx->id = id;
	return tx;
}

void Transaction::finalize()
{
	while(!nonce) {
		nonce = vnx::rand64();
	}
	id = calc_hash();
}

vnx::bool_t Transaction::is_valid() const
{
	for(const auto& op : execute) {
		if(!op) {
			return false;
		}
	}
	for(const auto& sol : solutions) {
		if(!sol) {
			return false;
		}
	}
	if(is_extendable && deploy) {
		return false;
	}
	if(parent && !parent->is_valid()) {
		return false;
	}
	return version == 0 && fee_ratio >= 1024 && calc_hash() == id;
}

hash_t Transaction::calc_hash() const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	buffer.reserve(4 * 1024);

	write_bytes(out, get_type_hash());
	write_field(out, "version", version);
	write_field(out, "nonce", 	nonce);
	write_field(out, "expires", expires);
	write_field(out, "fee_ratio", 	fee_ratio);
	write_field(out, "note", 	note);
	write_field(out, "salt", 	salt);
	write_field(out, "sender",	sender);
	write_field(out, "revoke",	revoke);
	write_field(out, "inputs",	inputs);
	write_field(out, "outputs", outputs);
	write_field(out, "execute");
	for(const auto& op : execute) {
		write_bytes(out, op ? op->calc_hash() : hash_t());
	}
	write_field(out, "deploy", deploy ? deploy->calc_hash() : hash_t());
	write_field(out, "parent", parent ? parent->calc_hash() : hash_t());
	write_field(out, "is_extendable", is_extendable);

	out.flush();

	return hash_t(buffer);
}

void Transaction::add_output(const addr_t& currency, const addr_t& address, const uint64_t& amount, const uint32_t& split)
{
	if(split == 0) {
		throw std::logic_error("split == 0");
	}
	if(split > 1000000) {
		throw std::logic_error("split > 1000000");
	}
	if(amount < split) {
		throw std::logic_error("amount < split");
	}
	uint64_t left = amount;
	for(uint32_t i = 0; i < split; ++i) {
		txio_t out;
		out.address = address;
		out.contract = currency;
		out.amount = i + 1 < split ? amount / split : left;
		left -= out.amount;
		outputs.push_back(out);
	}
}

std::shared_ptr<const Solution> Transaction::get_solution(const uint32_t& index) const
{
	if(index < solutions.size()) {
		return solutions[index];
	}
	return nullptr;
}

txio_t Transaction::get_output(const uint32_t& index) const
{
	if(index < outputs.size()) {
		return outputs[index];
	}
	if(index >= outputs.size()) {
		const auto offset = index - outputs.size();
		if(offset < exec_outputs.size()) {
			return exec_outputs[offset];
		}
	}
	throw std::logic_error("no such output");
}

std::vector<txio_t> Transaction::get_outputs() const
{
	auto res = outputs;
	res.insert(res.end(), exec_outputs.begin(), exec_outputs.end());
	return res;
}

std::vector<txio_t> Transaction::get_all_outputs() const
{
	if(parent) {
		return get_combined()->get_outputs();
	}
	return get_outputs();
}

std::vector<txin_t> Transaction::get_all_inputs() const
{
	if(parent) {
		return get_combined()->inputs;
	}
	return inputs;
}

uint64_t Transaction::calc_cost(std::shared_ptr<const ChainParams> params) const
{
	if(!params) {
		throw std::logic_error("!params");
	}
	uint128_t cost = params->min_txfee;
	cost += revoke.size() * params->min_txfee;
	cost += inputs.size() * params->min_txfee_io;
	cost += outputs.size() * params->min_txfee_io;

	for(const auto& in : inputs) {
		if(in.flags & txin_t::IS_EXEC) {
			cost += params->min_txfee_exec;
		}
	}
	for(const auto& op : execute) {
		if(op) {
			cost += params->min_txfee_exec + op->calc_cost(params);
		}
	}
	for(const auto& sol : solutions) {
		if(sol) {
			cost += sol->calc_cost(params);
		}
	}
	if(deploy) {
		cost += params->min_txfee_deploy + deploy->calc_cost(params);
	}
	if(parent) {
		cost += parent->calc_cost(params);
	}
	if(cost.upper()) {
		throw std::logic_error("tx cost amount overflow");
	}
	return cost;
}

void Transaction::merge_sign(std::shared_ptr<const Transaction> tx)
{
	std::unordered_map<uint32_t, uint32_t> import_map;
	for(size_t i = 0; i < inputs.size() && i < tx->inputs.size(); ++i)
	{
		auto& our = inputs[i];
		const auto& other = tx->inputs[i];

		if(other.solution < tx->solutions.size() && our.solution >= solutions.size())
		{
			auto iter = import_map.find(other.solution);
			if(iter != import_map.end()) {
				our.solution = iter->second;
			} else {
				our.solution = solutions.size();
				import_map[other.solution] = our.solution;
				solutions.push_back(tx->solutions[other.solution]);
			}
		}
	}
}

vnx::bool_t Transaction::is_signed() const
{
	for(const auto& in : inputs) {
		if(in.solution >= solutions.size()) {
			return false;
		}
	}
	return true;
}

void combine(std::shared_ptr<Transaction> out, const Transaction& tx)
{
	out->expires = std::min(out->expires, tx.expires);
	out->revoke.insert(out->revoke.begin(), tx.revoke.begin(), tx.revoke.end());
	out->inputs.insert(out->inputs.begin(), tx.inputs.begin(), tx.inputs.end());
	out->outputs.insert(out->outputs.begin(), tx.outputs.begin(), tx.outputs.end());
	out->exec_outputs.insert(out->exec_outputs.begin(), tx.exec_outputs.begin(), tx.exec_outputs.end());
	out->execute.insert(out->execute.begin(), tx.execute.begin(), tx.execute.end());

	if(tx.parent) {
		combine(out, *tx.parent);
	}
}

std::shared_ptr<const Transaction> Transaction::get_combined() const
{
	auto out = vnx::clone(*this);
	if(parent) {
		combine(out, *parent);
	}
	return out;
}








} // mmx
