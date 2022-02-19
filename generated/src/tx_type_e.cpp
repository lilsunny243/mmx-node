
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/tx_type_e.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 tx_type_e::VNX_TYPE_HASH(0x3b7f577c2cfd4c91ull);
const vnx::Hash64 tx_type_e::VNX_CODE_HASH(0xcaef97446a492b6aull);

vnx::Hash64 tx_type_e::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string tx_type_e::get_type_name() const {
	return "mmx.tx_type_e";
}

const vnx::TypeCode* tx_type_e::get_type_code() const {
	return mmx::vnx_native_type_code_tx_type_e;
}

std::shared_ptr<tx_type_e> tx_type_e::create() {
	return std::make_shared<tx_type_e>();
}

std::shared_ptr<tx_type_e> tx_type_e::clone() const {
	return std::make_shared<tx_type_e>(*this);
}

void tx_type_e::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void tx_type_e::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

vnx::bool_t tx_type_e::is_valid() const {
	switch(value) {
		case RECEIVE: return true;
		case REWARD: return true;
		case SPEND: return true;
	}
	return false;
}

std::string tx_type_e::to_string() const {
	switch(value) {
		case RECEIVE: return "\"RECEIVE\"";
		case REWARD: return "\"REWARD\"";
		case SPEND: return "\"SPEND\"";
	}
	return std::to_string(value);
}

std::string tx_type_e::to_string_value() const {
	switch(value) {
		case RECEIVE: return "RECEIVE";
		case REWARD: return "REWARD";
		case SPEND: return "SPEND";
	}
	return std::to_string(value);
}

std::string tx_type_e::to_string_value_full() const {
	switch(value) {
		case RECEIVE: return "mmx.tx_type_e.RECEIVE";
		case REWARD: return "mmx.tx_type_e.REWARD";
		case SPEND: return "mmx.tx_type_e.SPEND";
	}
	return std::to_string(value);
}

void tx_type_e::from_string(const std::string& _str) {
	std::string _name;
	vnx::from_string(_str, _name);
	from_string_value(_name);
}

void tx_type_e::from_string_value(const std::string& _name) {
	vnx::Variant var;
	vnx::from_string_value(_name, var);
	if(var.is_string()) {
		if(_name == "RECEIVE") value = RECEIVE;
		else if(_name == "REWARD") value = REWARD;
		else if(_name == "SPEND") value = SPEND;
		else value = enum_t(vnx::hash64(_name));
	} else {
		value = enum_t(std::stoul(_name.c_str(), nullptr, 0));
	}
}

void tx_type_e::accept(vnx::Visitor& _visitor) const {
	std::string _name;
	switch(value) {
		case RECEIVE: _name = "RECEIVE"; break;
		case REWARD: _name = "REWARD"; break;
		case SPEND: _name = "SPEND"; break;
	}
	_visitor.enum_value(value, _name);
}

void tx_type_e::write(std::ostream& _out) const {
	switch(value) {
		case RECEIVE: _out << "\"RECEIVE\""; break;
		case REWARD: _out << "\"REWARD\""; break;
		case SPEND: _out << "\"SPEND\""; break;
		default: _out << value;
	}
}

void tx_type_e::read(std::istream& _in) {
	from_string_value(vnx::read(_in).to_string_value());
}

vnx::Object tx_type_e::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.tx_type_e";
	_object["value"] = value;
	return _object;
}

void tx_type_e::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "value") {
			_entry.second.to(value);
		}
	}
}

vnx::Variant tx_type_e::get_field(const std::string& _name) const {
	if(_name == "value") {
		return vnx::Variant(value);
	}
	return vnx::Variant();
}

void tx_type_e::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "value") {
		_value.to(value);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const tx_type_e& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, tx_type_e& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* tx_type_e::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> tx_type_e::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.tx_type_e";
	type_code->type_hash = vnx::Hash64(0x3b7f577c2cfd4c91ull);
	type_code->code_hash = vnx::Hash64(0xcaef97446a492b6aull);
	type_code->is_native = true;
	type_code->is_enum = true;
	type_code->native_size = sizeof(::mmx::tx_type_e);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<tx_type_e>>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "value";
		field.code = {3};
	}
	type_code->enum_map[940023181] = "RECEIVE";
	type_code->enum_map[3842121424] = "REWARD";
	type_code->enum_map[2341768809] = "SPEND";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::tx_type_e& value, const TypeCode* type_code, const uint16_t* code) {
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
		Variant tmp;
		vnx::read(in, tmp, type_code, code);
		if(tmp.is_string()) {
			vnx::from_string(tmp.to_string(), value);
		} else if(tmp.is_ulong()) {
			value = ::mmx::tx_type_e::enum_t(tmp.to<uint32_t>());
		} else {
			value = ::mmx::tx_type_e();
		}
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
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.value, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::tx_type_e& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_STRING) {
		vnx::write(out, value.to_string_value(), nullptr, code);
		return;
	}
	if(code && code[0] == CODE_UINT32) {
		vnx::write(out, value.value, nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_tx_type_e;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::tx_type_e>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.value);
}

void read(std::istream& in, ::mmx::tx_type_e& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::tx_type_e& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::tx_type_e& value) {
	value.accept(visitor);
}

void read(TypeInput& in, ::mmx::tx_type_e::enum_t& value, const TypeCode* type_code, const uint16_t* code) {
	uint32_t tmp = 0;
	vnx::read(in, tmp, type_code, code);
	value = ::mmx::tx_type_e::enum_t(tmp);
}

void write(TypeOutput& out, const ::mmx::tx_type_e::enum_t& value, const TypeCode* type_code, const uint16_t* code) {
	vnx::write(out, uint32_t(value), type_code, code);
}

template<>
std::string to_string(const ::mmx::tx_type_e& _value) {
	return _value.to_string();
}

template<>
std::string to_string_value(const ::mmx::tx_type_e& _value) {
	return _value.to_string_value();
}

template<>
std::string to_string_value_full(const ::mmx::tx_type_e& _value) {
	return _value.to_string_value_full();
}

template<>
std::string to_string(const ::mmx::tx_type_e::enum_t& _value) {
	return ::mmx::tx_type_e(_value).to_string();
}

template<>
std::string to_string_value(const ::mmx::tx_type_e::enum_t& _value) {
	return ::mmx::tx_type_e(_value).to_string_value();
}

template<>
std::string to_string_value_full(const ::mmx::tx_type_e::enum_t& _value) {
	return ::mmx::tx_type_e(_value).to_string_value_full();
}

bool is_equivalent<::mmx::tx_type_e>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::tx_type_e::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
