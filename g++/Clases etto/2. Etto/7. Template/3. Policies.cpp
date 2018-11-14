//POLICIES IMPORTANTE
#include<iostream>
#include<string>

using namespace std;

template <typename HablarPolicy>
struct Primate
{
	HablarPolicy hablarPolicy;
	void hablar() const {hablarPolicy.hablar();}
};

struct HumanoHablarPolicy
{
	void hablar() const {cout<<"blablabla\n";}
};

struct MonoHablarPolicy
{
	void hablar() const {cout<<"UUU\n";}
};
using Humano = Primate <HumanoHablarPolicy>;
using Mono = Primate <MonoHablarPolicy>;
int main()
{
	Humano h;
	h.hablar();
	Mono m;
	m.hablar();
}
//de no constante a constante si pero al reves no