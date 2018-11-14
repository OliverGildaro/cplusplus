#include <iostream>
#include <string>
#include "lib_object.h"

using namespace std;


lib_object::lib_object()
{
	
}
lib_object::~lib_object()
{
}
std::string lib_object::to_string() const
{
	return "x";
}
bool lib_object::operator ==(const lib_object& obj) const
{
	return false;
}
std::string lib_object::get_class_name()const
{
	return "lib_object";
}