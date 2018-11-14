#ifndef __LIB_OBJECT_H
#define __LIB_OBJECT_H
#include<string>

class lib_object{
	
public:
      lib_object();
      virtual ~lib_object();
      virtual std::string to_string() const;
      virtual bool operator ==(const lib_object&) const;
      virtual std::string get_class_name()const;
};

#endif