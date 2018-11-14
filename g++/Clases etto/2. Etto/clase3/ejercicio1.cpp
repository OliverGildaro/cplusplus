//herencia virtual
#include <iostream>
using namespace std;
class A
{
	int n;
public:
	A(int n):n{n}
	{
		cout<<"A\n";
	}
	virtual~A(){}
};
class X: public virtual A
{
public:
	X():A(843){}
};
class B: public virtual A
{
	string s;
public:
	B(const string &s):A{321},s{s}
	{
		cout<<"B\n";
	}
};
class C:public virtual X,public virtual B
{
public:
	C():A(400),X(),B("hola")
	{}
};
int main()
{
	A* a= new C();
	delete a;

}//la clase hija iene que llamar a todos los constructores de las clases padres
//cuando uses herencia virtual crear clases con construtores vacios para que llamen a esas 