
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_FarmerBase_HXX_
#define INCLUDE_mmx_FarmerBase_HXX_

#include <mmx/package.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Hash64.hpp>
#include <vnx/Module.h>


namespace mmx {

class FarmerBase : public ::vnx::Module {
public:
	
	uint32_t default_wallet = 0;
	uint32_t default_address = 0;
	std::string node_server = "Node";
	std::string wallet_server = "Wallet";
	vnx::optional<::mmx::addr_t> reward_addr;
	vnx::optional<::mmx::addr_t> project_addr;
	vnx::float64_t devfee_ratio = 0.025;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xff732ba14d9d1abull;
	
	FarmerBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const FarmerBase& _value);
	friend std::istream& operator>>(std::istream& _in, FarmerBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual ::vnx::Hash64 get_mac_addr() const = 0;
	virtual std::shared_ptr<const ::mmx::BlockHeader> sign_block(std::shared_ptr<const ::mmx::BlockHeader> block, const uint64_t& reward_amount) const = 0;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_FarmerBase_HXX_
