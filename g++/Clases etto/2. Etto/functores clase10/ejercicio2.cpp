
#include <cstdio>
#include<iostream>
#include<string>

using namespace std;
using namespace std::string_literals;
int cint(int x, int y)
{
	return x-y;
}
int cstr(string x,string y)
{
	return x.compare(y);
}
template <class T>
struct mcomp
{
	bool asc;
	int operator()(const T&a,const T&b)const
	{
		if (a==b)return 0;
		if (asc)
		{
			return a<b?-1:1;
		}
		return b<a?-1:1;
	}
};
template<class T, class PROC>
void msort(const T& a, const T&  b,/*int (*p)(T a,T b)*/PROC p)
{
	if(p(a,b)<0)
	{
		cout<<a<<"\n";
		cout<<b<<"\n";
	}
	else
	{
		cout<<b<<"\n";
		cout<<a<<"\n";
	}
}
int main()
{
	msort(6,9,cint);
	puts("xxx");
	msort("hola"s,"amigos"s,cstr);
	mcomp<int> c1{true};
	msort(16,14,c1);
	mcomp<string> c2{false};
	msort("gatos"s,"perros"s,c2);
}

//para que me agarre c1 y c2 se tiene que hacer un template que de llame un PROC 