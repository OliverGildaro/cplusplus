#ifndef __LIB_STRING_H
#define __LIB_STRING_H
#include "lib_object.h"
#include<string>

class lib_string: public lib_object
{
	std::string value;
	
	public:
	lib_string(std::string value);
	~lib_string();
	std::string to_string() const;
	bool operator==(const lib_object&)const override;
	std::string get_class_name()const override;
};
#endif