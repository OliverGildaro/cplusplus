//finally
#include<iostream>
using namespace std;
struct wint 
{
	int *s;
	~wint()
	{
		delete s;
		cout<<"p\n";
	}
};
int main()
{
	try
	{
		wint s{new int{18}};
		throw 2;
	}
	catch(...)
	{
		cerr<<"leak\n";
	}
}