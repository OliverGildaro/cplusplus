#include <iostream>
//structs en c
//*solo pueden contener atributos
//*no hay herencia, ni polimorfirmo
#include <cstring>
using namespace std;

typedef struct
{
	char* name;
	int id;
}Person;

void init_person(Person* p,const char* n,int id)
{
	size_t len = strlen(n);
	p->name=(char*)malloc(len+1);
	memcpy(p->name,n,len+1);
	p->id = id;
}

void free_person(Person* p)
{
	free(p->name);
}

int main()
{
	Person p;
	init_person(&p,"juan perez",645);

	puts(p.name);

	free_person(&p);
}