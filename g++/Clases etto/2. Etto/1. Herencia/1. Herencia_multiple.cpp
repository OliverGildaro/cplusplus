//Herencia Multiple
#include <cstdio>
#include <iostream>
using namespace std;
class A
{
public:
	int x;
	void m(){puts ("hello");}
	
	
};
class B
{
public:
	int y;
	void n(){puts ("bye");}
	
};
class AB:public A,public B
{

	
};
int main()
{
	AB ab;
	ab.x =20;
	ab.y=12;
	cout<<ab.x<<"\n";
	cout<<ab.y<<"\n";
	ab.m();
	ab.n();
}