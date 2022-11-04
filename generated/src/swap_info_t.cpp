
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/swap_info_t.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/swap_user_info_t.hxx>
#include <mmx/uint128.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 swap_info_t::VNX_TYPE_HASH(0x7586be908f15ae8ull);
const vnx::Hash64 swap_info_t::VNX_CODE_HASH(0xe3f91b29b0009f52ull);

vnx::Hash64 swap_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string swap_info_t::get_type_name() const {
	return "mmx.swap_info_t";
}

const vnx::TypeCode* swap_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_swap_info_t;
}

std::shared_ptr<swap_info_t> swap_info_t::create() {
	return std::make_shared<swap_info_t>();
}

std::shared_ptr<swap_info_t> swap_info_t::clone() const {
	return std::make_shared<swap_info_t>(*this);
}

void swap_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void swap_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void swap_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_swap_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, tokens);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, wallet);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, balance);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, fees_paid);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, user_total);
	_visitor.type_end(*_type_code);
}

void swap_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"address\": "; vnx::write(_out, address);
	_out << ", \"tokens\": "; vnx::write(_out, tokens);
	_out << ", \"wallet\": "; vnx::write(_out, wallet);
	_out << ", \"balance\": "; vnx::write(_out, balance);
	_out << ", \"fees_paid\": "; vnx::write(_out, fees_paid);
	_out << ", \"user_total\": "; vnx::write(_out, user_total);
	_out << "}";
}

void swap_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object swap_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.swap_info_t";
	_object["address"] = address;
	_object["tokens"] = tokens;
	_object["wallet"] = wallet;
	_object["balance"] = balance;
	_object["fees_paid"] = fees_paid;
	_object["user_total"] = user_total;
	return _object;
}

void swap_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "balance") {
			_entry.second.to(balance);
		} else if(_entry.first == "fees_paid") {
			_entry.second.to(fees_paid);
		} else if(_entry.first == "tokens") {
			_entry.second.to(tokens);
		} else if(_entry.first == "user_total") {
			_entry.second.to(user_total);
		} else if(_entry.first == "wallet") {
			_entry.second.to(wallet);
		}
	}
}

vnx::Variant swap_info_t::get_field(const std::string& _name) const {
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "tokens") {
		return vnx::Variant(tokens);
	}
	if(_name == "wallet") {
		return vnx::Variant(wallet);
	}
	if(_name == "balance") {
		return vnx::Variant(balance);
	}
	if(_name == "fees_paid") {
		return vnx::Variant(fees_paid);
	}
	if(_name == "user_total") {
		return vnx::Variant(user_total);
	}
	return vnx::Variant();
}

void swap_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "address") {
		_value.to(address);
	} else if(_name == "tokens") {
		_value.to(tokens);
	} else if(_name == "wallet") {
		_value.to(wallet);
	} else if(_name == "balance") {
		_value.to(balance);
	} else if(_name == "fees_paid") {
		_value.to(fees_paid);
	} else if(_name == "user_total") {
		_value.to(user_total);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const swap_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, swap_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* swap_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> swap_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.swap_info_t";
	type_code->type_hash = vnx::Hash64(0x7586be908f15ae8ull);
	type_code->code_hash = vnx::Hash64(0xe3f91b29b0009f52ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::swap_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<swap_info_t>>(); };
	type_code->fields.resize(6);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "tokens";
		field.code = {11, 2, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "wallet";
		field.code = {11, 2, 11, 16, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "balance";
		field.code = {11, 2, 11, 16, 1};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "fees_paid";
		field.code = {11, 2, 11, 16, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "user_total";
		field.code = {11, 2, 11, 16, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::swap_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.tokens, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.wallet, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.balance, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.fees_paid, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.user_total, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::swap_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_swap_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::swap_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.address, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.tokens, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.wallet, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.balance, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.fees_paid, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.user_total, type_code, type_code->fields[5].code.data());
}

void read(std::istream& in, ::mmx::swap_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::swap_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::swap_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::swap_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::swap_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
