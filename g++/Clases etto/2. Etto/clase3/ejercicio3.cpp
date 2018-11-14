//int x = (int) 4.14;
/*
int *y=&x;
long long z= (long long)y;

no hacer 
char* p =(char* )"hola";

*/
// en c++ cuando tu programa corre no cuesta nada
/*
int x = static_cast<int>(3.14);

int *y=&x;
lon lon z= reinterpret_cast(y); //cambia de puntero a numero en este caso agarra la direccion de memoria

char* p= const_cast<char*>("hola");
*/

//dynamic_cast//este tiene un costo n tiempo de ejecucion
#include <iostream>
#include <cstdio>
using namespace std;
struct P
{
	virtual ~P()
	{		
	}
	virtual void show()const = 0 ;
};
struct Q:P
{
	int n;
	Q(int n):n{n}
	{}
	void show()const override
	{
		cout<<n<<"\n";
	}
	string to_string()const
	{
		return std::to_string(n);
	}
};
struct R:P
{
	string s;
	R(const string& s):s{s}
	{}
	void show()const override
	{
		cout<<s<<"\n";
	}
};
void do_something(P& p)
{
	try
	{
		Q& q=dynamic_cast<Q&>(p);
		cout<<"ts:"<<q.to_string()<<"\n";
	}
	catch(...){cout<<"badcast";}
}
int main()
{
	P *q=new Q(114);//de un hijo a un tipo padre
	P *r=new R("hola");
	do_something(*r);// aqui no se puede el dynamic
	do_something(*q);// aqui si se puede el dynamic

}