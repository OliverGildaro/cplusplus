#include "lib_rawstring.h"

#include <string.h>
 
lib_rawstring::lib_rawstring(const char* value)
{
	auto len = strlen(value);
	this->value = new char[len + 1];
	memcpy(this->value, value, len + 1);
}
lib_rawstring::~lib_rawstring()
{
	delete[]value;
}
std::string lib_rawstring::to_string() const
{
	return value;
}

bool lib_rawstring::operator==(const lib_object& src)const 
{
	if(src.get_class_name() == "lib_rawstring")
		return strcmp(value, ((lib_rawstring&)src).value) == 0;
	else
		return false;
}

std::string lib_rawstring::get_class_name()const
{
	return "lib_rawstring";
}