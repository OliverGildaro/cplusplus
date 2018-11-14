#include "lib_double.h"
#include <iostream>
#include <string>

using namespace std;

lib_double::lib_double(double value):value{value}
{
	
}
lib_double:: ~lib_double()
{
		
}
std::string lib_double::to_string()const
{
		return std::to_string(value);
	
}

bool lib_double::operator==(const lib_object& obj)const
{
	if(obj.get_class_name() == "lib_double")
		return (value==((lib_double&)obj).value);
	else
		return false;
}

std::string lib_double::get_class_name()const
{
	return "lib_double";
}