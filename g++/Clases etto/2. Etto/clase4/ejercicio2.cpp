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
/*	int x=2;
	int y=0;
	cout<<(x/y)<<"\n";//cuando tienes un error de aritmetica el programa muere*/
	/*int* y= nullptr;
	*y=4;*///esto es mal uso de la memoria
	//throw "hola";
	throw 4;
}
void y()
{
	try
	{
		cout<<"oops\n";
		z();
		cout<<"i did it again\n";
	}
	catch(const char* s)
	{
		cerr<<"Error"<<s<<"\n";
	}
}
void x()
{
	y();
	cout<<"UFF\n";
}
int main()
{
	try
	{
		A a;
		x();		
	}
	catch(int n)
	{
		cerr<<"CODIGO "<<n<<"\n";
	}
	catch(...)//(...)significa que agarras todas las excepciones
	{
		cerr<<"unknow error\n";
	}
	cout<<"Bye\n";
}