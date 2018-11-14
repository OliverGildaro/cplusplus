#include <cstdio>
#include<iostream>
#include<string>

using namespace std;
// using namespace std::string_literals;
template<typename T>
T sumar(const T& a,const T& b)
{
	return a+b;
}

template<typename T, typename...ARGS>//ARGdice que es un conjunto de tiposy ARGS se llama parameter pack siempre es uno tyepname T y luego un conjunto que es arg
//cuando pones typename... se llama pack expancion
void sumar(const T& x, const ARGS&...args)
{
	return x + sumar(args...);
}

template<typename...ARGS>//ARGdice que es un conjunto de tiposy ARGS se llama parameter pack siempre es uno tyepname T y luego un conjunto que es arg
//cuando pones typename... se llama pack expancion
void sum(const ARGS&...args)
{
	cout<<sumar(args...)<<"\n";
}

int main()
{
	sum(6,7);
	sum(8.3,7.1);
	sum(8,7,5,6,7,8);


}

