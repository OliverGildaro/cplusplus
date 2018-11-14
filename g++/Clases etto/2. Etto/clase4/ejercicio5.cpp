#include <stdexcept>
#include <iostream>
using namespace std;
class my_exception:public std::exception
{
public:
	const char* what()const noexcept override
	{
		return "today is wednesday";
	}
};
int main()
{
	try
	{
		cout<<"hoy\n";
		throw my_exception{};
	}
	catch (const exception& ex)
	{
		cout<<ex.what()<<"\n";
	}
}