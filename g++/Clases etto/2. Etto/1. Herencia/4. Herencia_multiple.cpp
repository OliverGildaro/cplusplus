#include <cstdio>
#include <iostream>

using namespace std;

class M
{
public:
	void p()
	{
		puts("M");
	}
};

class N
{
public:
	void p ()
	{
		puts ("N");
	}
};

class MN : public M, public N
{
public:
	void p()
	{
		puts("MN");
	}
	void q()
	{
		M::p();
		N::p();
	}
};

int main()
{
	M m;
	m.p();
	N n;
	n.p();
	MN mn;
	mn.p();
	mn.q();
}