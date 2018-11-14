//"POOR MAN POLIMORFISMO"
#include <iostream>

#include <cstring>

using namespace std;

typedef struct 
{
	int age;
	int type;
	void (*hablar)();
	void (*comer)();
}Animal;

typedef struct 
{
	Animal a;
	int n_eggs;
}Oviparo;

void perro_hablar() {puts("guau");}

void perro_comer() {puts("come gatos");}

void gato_hablar() {puts("miao");}

void gato_comer() {puts("come ratones");}

void pollo_hablar() {puts("KIKIRIKI");}


void new_perro(Animal* a,int age, int type)
{
	a->age=age;
	a->type=type;
	a->hablar = perro_hablar;
	a->comer = perro_comer;
}

void new_gato(Animal* g,int age)
{
	g->age=age;
	g->hablar = gato_hablar;
	g->comer = gato_comer;
}

void new_pollo(Oviparo* p,int age, int eggs)
{
	p->a.age=age;
	p->a.type=3;
	p->a.hablar = pollo_hablar;
	p->a.comer = NULL;
	p->n_eggs = eggs;	

}

void say_something(Animal* a)
{
	a->hablar();
	if(a->type==3)
	{
		Oviparo* ox=(Oviparo*) a;
		printf("%d\n",ox->n_eggs);
	}
}

int main()
{
	/*
	Animal perro;
	Animal gato;

	new_perro(&perro,15);
	new_gato(&gato,1);

	perro.comer();
	perro.hablar();

	gato.comer();
	gato.hablar();
	*/

	Oviparo pollo;

	new_pollo(&pollo,1,200);

	say_something((Animal*)&pollo); //casteamos para que pueda correr el programa
}
