#ifndef __LIB_INTEGER_H
#define __LIB_INTEGER_H
#include "lib_object.h"
#include<string>

class lib_integer: public lib_object 
{
	size_t value;	
	public:
	lib_integer(size_t value);
	~lib_integer();
	std::string to_string() const;
	bool operator==(const lib_object&)const override;
	std::string get_class_name()const override;
};
#endif