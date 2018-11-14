#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
	public:
		size_t size;
		size_t edad;

};

class Perro : Animal
{
	public:
		char raza[16];

};

int main()
{
	Animal a{60,5};
	cout<<a.size<<endl;

	Perro p;

	strcpy(p.raza,"chapi");
	cout<<p.raza<<endl;

	p.size = 40;
	cout<<p.size<<endl;
}