#include "lib_array_list.h"
#include <cstdio>

lib_array_list::lib_array_list()
:len{0},sizememory{4}, objs{new lib_object*[4]}
{

}

lib_array_list::~lib_array_list()
{
	for(size_t i = 0; i < len; i++){
		delete objs[i];
	}
	delete[] objs;
	//puts("bye");
}	

void lib_array_list::add(lib_object* obj)
{
	if(len<sizememory)
	{
		objs[len] = obj;
		len++;
	}else{
		size_t aux;
		aux = 2*sizememory;
		lib_object** array_aux = new lib_object*[aux];
		for(size_t i = 0; i < len; i++)
		{
			array_aux[i] = objs[i];
		}		
		delete []objs;
		objs = array_aux;
		objs[len++] = obj;
		sizememory = aux;
	}		
}

int lib_array_list::find(const lib_object& obj) const
{
	for(size_t i=0; i<len; i++)
	{
		if(obj == *objs[i])
		{
			return i;
		}
	}
	return -1;
}
lib_object& lib_array_list::get(size_t pos){
	
	return *(objs[pos]);
}
size_t lib_array_list::length()const{
	return len;
}