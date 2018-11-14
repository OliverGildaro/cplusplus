#include <iostream>
using namespace std;

template<class T>//template<typename T>//estas lineas son lo mismo
T sum (T a,T b) // este template acepta dos parametros del mismo tipo
{
	return a+b;
}

int sum (int a, int b) //este recibe un entero y un double (casteo implicito)
{
	cout<<"hola\n";
	return a+b;
}

int main()
{
	auto p=sum(8,10.34);
	cout<<p<<"\n";
	double q= sum(3.14,8.16);
	cout<<q<<"\n";
}