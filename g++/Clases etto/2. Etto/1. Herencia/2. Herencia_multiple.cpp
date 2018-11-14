#include <cstdio>
#include <iostream>
using namespace std;

struct SeMueve
{
	void mover(int pos)
	{
		cout<<"me movi"<<pos<<"m\n";
	}
};

struct Vuela
{
	void volar(int a)
	{
		cout<<"vuelo"<<a<<"m \n";
	}
};

struct Come
{
	void comer(int kg)
	{
		cout<<"comi"<<kg<<"kg\n";
	}
};

struct Vaca : SeMueve, Come
{
	void darCarne(int kgs)
	{
		cout<<"dar"<<kgs<<"kgs\n";
	}
};

struct Paloma : SeMueve, Come, Vuela
{

};

struct Helicoptero : Vuela
{
	
};

void alimentar(Come& c)
{
	c.comer(10);
};

int main ()
{
	Paloma p;
	Helicoptero h;
	Vaca v;
	p.volar(200);
	p.mover(100);
	h.volar(100);
	puts("xxx");
	alimentar(p);
	alimentar(v);
}