#ifndef VALUE_NOT_FOUND_H
#define VALUE_NOT_FOUND_H
#include <stdexcept>
template<typename K>
class value_not_found: public std::exception
{
	public:
	const K& get_key() const
	{
		throw 1;
	}
};
#endif