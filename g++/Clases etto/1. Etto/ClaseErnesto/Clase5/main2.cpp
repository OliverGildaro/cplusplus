//punteros a funciones
#include <iostream>

using namespace std;

/*
void sum(int a, int b)
{
	cout<<a+b<<endl;
}

void sub(int a, int b)
{
	cout<<a-b<<endl;
}

int main()
{
	void(*p)(int, int); //p es un puntero que apunta a una funcion que recibe dos parametros y devuelve un void

	p = sum;
	p(6,10);

	p = sub;
	p(20,5);
}
*/


#include <stdlib.h>

int fc(const void* a,const void* b)
{
	int* p = (intx)a;
	int* q = (intx)b;

	return *p-*q;
}

int main()
{
	ins s[] = {1,2,3,4,5};

	qsort(s,5,sizeof(int),fc);

	for(int i:s)
		cout<<i<<endl;
}