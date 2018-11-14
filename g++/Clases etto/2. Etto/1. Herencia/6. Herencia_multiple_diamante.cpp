#include <cstdio>
#include <iostream>

using namespace std;

struct R
{
	int x;
};

struct S1 : R
{ };

struct S2 : R
{ };

struct T : S1, S2
{ };

int main()
{
	T p;
	p.S1::x=25;
	p.S2::x=14;
	cout<<p.S1::x<<"\n";
	cout<<p.S2::x<<"\n";
}