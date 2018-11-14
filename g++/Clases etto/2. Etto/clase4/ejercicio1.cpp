//cuando se pone un throw en un codigo vuelve hasta donde hay un catch
#include <iostream> 
using namespace std;
struct A
{
	A()
	{
		cout<<"A\n";
	}
	~A()
	{
		cout<<"Bye A\n";
	}
};
void z()
{
	cout<<"excep\n";
	throw 1;
}
void y()
{
	cout<<"oops\n";
	z();
	cout<<"i did it again\n";
}
void x()
{
	y();
}
int main()
{
	try
	{
		A* b=new A();
		A a;
		x();
		delete b;
	}
	catch(...)//(...)significa que agarras todas las excepciones
	{
		cerr<<"unknow error\n";
	}
	cout<<"Bye\n";
}