//especializacion con clases
#include<iostream>
#include<string>

using namespace std;

template <typename T>
struct A
{
	T n;
	void show()const
	{
            cout << "Struct A\n";
		cout << n << "\n";
	}
};

template <typename T>
struct A <T*>
{
	T* n;

      A(T* n)//2. Apunta al objeto X ya construido
      :n{n} {cout << "Constructor especializado\n";}

	void print()const
	{
            cout << "Struct A specializado\n";
		cout << *n << "\n";//3. aqui llama a la funcion cout que sobreescribimos
	}
	~A(){delete n;}
};

struct X
{
	int p=8;
	X() {cout<<"Hola\n";} //1. construye un objeto con p=8
	~X() {cout<<"bye\n";}
};

ostream& operator<<(ostream& os, const X& obj)//4. imprime el objeto de x
{
	cout << "Operator <<\n";
	os<<obj.p;
	return os;
}


int  main()
{
	A<int> a{614};
	a.show();

	A<int*> c{new int{418}};//el constructor recibe un puntero
	c.print();

	A<X*> d{new X{}};
	d.print();
}