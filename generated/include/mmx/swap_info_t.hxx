
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_swap_info_t_HXX_
#define INCLUDE_mmx_swap_info_t_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/swap_user_info_t.hxx>
#include <mmx/uint128.hpp>


namespace mmx {

struct MMX_EXPORT swap_info_t {
	
	
	::mmx::addr_t address;
	std::array<::mmx::addr_t, 2> tokens = {};
	std::array<::mmx::uint128, 2> wallet = {};
	std::array<::mmx::uint128, 2> balance = {};
	std::array<::mmx::uint128, 2> fees_paid = {};
	std::array<::mmx::uint128, 2> user_total = {};
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x7586be908f15ae8ull;
	
	swap_info_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	vnx::float64_t get_price() const;
	uint64_t get_trade_amount(const uint32_t& i = 0, const uint64_t& amount = 0) const;
	std::array<uint64_t, 2> get_earned_fees(const ::mmx::swap_user_info_t& user = ::mmx::swap_user_info_t()) const;
	std::array<uint64_t, 2> get_remove_amount(const ::mmx::swap_user_info_t& user = ::mmx::swap_user_info_t(), const std::array<uint64_t, 2>& amount = {}) const;
	
	static std::shared_ptr<swap_info_t> create();
	std::shared_ptr<swap_info_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const swap_info_t& _value);
	friend std::istream& operator>>(std::istream& _in, swap_info_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void swap_info_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<swap_info_t>(6);
	_visitor.type_field("address", 0); _visitor.accept(address);
	_visitor.type_field("tokens", 1); _visitor.accept(tokens);
	_visitor.type_field("wallet", 2); _visitor.accept(wallet);
	_visitor.type_field("balance", 3); _visitor.accept(balance);
	_visitor.type_field("fees_paid", 4); _visitor.accept(fees_paid);
	_visitor.type_field("user_total", 5); _visitor.accept(user_total);
	_visitor.template type_end<swap_info_t>(6);
}


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::swap_info_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_swap_info_t_HXX_
