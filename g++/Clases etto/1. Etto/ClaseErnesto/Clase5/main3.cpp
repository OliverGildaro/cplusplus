
#include <iostream>
#include <stdlib.h>
using namespace std;

//void a(void (*p)(), void(*q)()
typedef void (*FUNC)();

void a(FUNC p, FUNC q)
{
	p();
	q();
}

void b()
{
	cout<<"hi"<<endl;
}

void c()
{
	cout<<"bye"<<endl;
}

int main()
{
	a(b,c);
}