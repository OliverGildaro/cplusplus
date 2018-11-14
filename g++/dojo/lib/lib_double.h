#ifndef __LIB_DOUBLE_H
#define __LIB_DOUBLE_H
#include "lib_object.h"
#include<string>

class lib_double: public lib_object
{
	double value;
	
	public:
	lib_double(double value);
	~lib_double();
	std::string to_string() const;
	bool operator==(const lib_object&)const override;
	std::string get_class_name()const override;
};
#endif