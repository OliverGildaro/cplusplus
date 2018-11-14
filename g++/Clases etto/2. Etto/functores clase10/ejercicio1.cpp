//functores functors o function objects
//es un objeto de una clase normal que se invoca como si fuera una funcion
#include <cstdio>
#include<iostream>
#include<string>

using namespace std;
class incr
{
public:
	void operator()(int n)const
	{
		cout<<(n+1)<<"\n";
	}
};
int main()
{
	incr i;
	i(16);//function object
}