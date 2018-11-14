#ifndef VALUE_NOT_FOUND_H
#define VALUE_NOT_FOUND_H
#include <stdexcept>
template<typename K>
class value_not_found: public std::exception
{
	K key;
	public:
	value_not_found(const K& key)
	:key{key}
	{		
	}
	const K& get_key() const
	{
		return key;
	}
};
#endif