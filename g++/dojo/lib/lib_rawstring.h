#ifndef __LIB_RAWSTRING_H
#define __LIB_RAWSTRING_H
#include "lib_object.h"

#include <string>

class lib_rawstring: public lib_object
{
	char* value;
	
	public:
	lib_rawstring(const char* value);
	~lib_rawstring();
	std::string to_string() const;
	bool operator==(const lib_object&)const override;
	std::string get_class_name()const override;
};
#endif