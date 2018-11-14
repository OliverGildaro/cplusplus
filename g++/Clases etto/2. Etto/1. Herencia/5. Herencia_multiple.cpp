#include <cstdio>
#include <iostream>

using namespace std;

struct B1
{
	int x;
	int y;
};

struct B2
{
	int x;
	int h;
};

struct H1:B1,B2
{
	H1(int x,int y,int h):B1{x,y},B2{x,h} { }
};

int main()
{
	H1 h{1,4,5};
	cout<<h.B1::x<<"\n";
	cout<<h.B2::x<<"\n";
	cout<<h.y<<"\n";
	cout<<h.h<<"\n";
	h.B2::x=110;
	cout<<h.B2::x<<"\n";
}