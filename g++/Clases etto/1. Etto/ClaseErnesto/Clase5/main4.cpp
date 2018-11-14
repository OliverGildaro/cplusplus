
#include <iostream>
#include <stdlib.h>
typedef void (*Action)();

using namespace std;

void a1()
{
	cout<<"hello\n";
}

void a2()
{
	cout<<"romulo\n";
}

void a3()
{
	cout<<"alvaro\n";
}

int main()
{
	Action a[] = {a1,a2,a3};

	for(auto p:a)//a siempre debe ser un array con corchetes []; {const auto& p"a}
		p();
}