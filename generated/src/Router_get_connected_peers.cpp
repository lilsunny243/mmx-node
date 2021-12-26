
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Router_get_connected_peers.hxx>
#include <mmx/Router_get_connected_peers_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Router_get_connected_peers::VNX_TYPE_HASH(0x8682feb65fbb77feull);
const vnx::Hash64 Router_get_connected_peers::VNX_CODE_HASH(0xc4d46e93242548d5ull);

vnx::Hash64 Router_get_connected_peers::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Router_get_connected_peers::get_type_name() const {
	return "mmx.Router.get_connected_peers";
}

const vnx::TypeCode* Router_get_connected_peers::get_type_code() const {
	return mmx::vnx_native_type_code_Router_get_connected_peers;
}

std::shared_ptr<Router_get_connected_peers> Router_get_connected_peers::create() {
	return std::make_shared<Router_get_connected_peers>();
}

std::shared_ptr<vnx::Value> Router_get_connected_peers::clone() const {
	return std::make_shared<Router_get_connected_peers>(*this);
}

void Router_get_connected_peers::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Router_get_connected_peers::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Router_get_connected_peers::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Router_get_connected_peers;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Router_get_connected_peers::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Router.get_connected_peers\"";
	_out << "}";
}

void Router_get_connected_peers::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Router_get_connected_peers::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Router.get_connected_peers";
	return _object;
}

void Router_get_connected_peers::from_object(const vnx::Object& _object) {
}

vnx::Variant Router_get_connected_peers::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Router_get_connected_peers::set_field(const std::string& _name, const vnx::Variant& _value) {
	throw std::logic_error("no such field: '" + _name + "'");
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Router_get_connected_peers& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Router_get_connected_peers& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Router_get_connected_peers::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Router_get_connected_peers::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Router.get_connected_peers";
	type_code->type_hash = vnx::Hash64(0x8682feb65fbb77feull);
	type_code->code_hash = vnx::Hash64(0xc4d46e93242548d5ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Router_get_connected_peers);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Router_get_connected_peers>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Router_get_connected_peers_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Router_get_connected_peers& value, const TypeCode* type_code, const uint16_t* code) {
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
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Router_get_connected_peers& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Router_get_connected_peers;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Router_get_connected_peers>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::mmx::Router_get_connected_peers& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Router_get_connected_peers& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Router_get_connected_peers& value) {
	value.accept(visitor);
}

} // vnx
