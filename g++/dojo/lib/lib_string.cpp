#include "lib_string.h"


lib_string::lib_string(std::string value):value{value}
{
	
}
lib_string::~lib_string()
{
	
}
std::string lib_string::to_string()const
{
		return value;
}


bool lib_string::operator==(const lib_object& obj)const
{
	if(obj.get_class_name() == "lib_string")
		return (value==((lib_string&)obj).value);
	else
		return false;
}

std::string lib_string::get_class_name()const
{
	return "lib_string";
}