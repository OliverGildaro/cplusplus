#include "lib_integer.h"
#include <iostream>

using namespace std;

lib_integer::lib_integer(size_t value):value{value}
{
	
}
lib_integer:: ~lib_integer()
{
	
}
std::string lib_integer::to_string()const
{
		return std::to_string(value);
}
bool lib_integer::operator==(const lib_object& obj)const
{
	if(obj.get_class_name() == "lib_integer")
		return (value==((lib_integer&)obj).value);
	else
		return false;
}

std::string lib_integer::get_class_name()const
{
	return "lib_integer";
}