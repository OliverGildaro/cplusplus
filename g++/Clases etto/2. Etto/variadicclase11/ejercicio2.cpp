// g++ ............-o3
// g++ ............-o2

#include <cstdio>
#include<iostream>
#include<string>

using namespace std;

template<class T>
void sshow(const T& a)
{
	cout<<a<<"\n";
}

template<typename T,typename...ARGS>
void sshow(const T& x,const ARGS&...args)
{
	cout<<x<<"\n";
	sshow(args...);
}

template<class...ARGS>
void show(const ARGS&...args)
{
	sshow(args...);
}
/*************PRIMERA VERSION*******************/

/*string join (const string&,const string& var)
{
	return var;
}
template<typename...args>
string join(const string& sep,const string& var,const args...ag)
{	
	return var+sep+join(sep,ag...);
}*/
/********************************/
void inner_join(string& aux,const string& sep,const string& name)
{
	aux=aux+name;
}
template<typename...args>
void inner_join(string& aux,const string& sep,const string& name,const args&...ag )
{
	cout<<"/********************/"<<"\n";
	cout<<aux<<"\n";
	aux=aux+name+sep;
	inner_join(aux,sep,ag...);
}
template<typename...args>
string join(const string& sep, const args&...ag)
{
	string aux;
	inner_join(aux,sep,ag...);
	return aux;
}


int main()
{
	/**********PRIMERA VERSION************
	show(6,8,true,"hola",3.1415);
	show("hola",26,"hello");
	string aux;
	string p = join(",","juan","jose","pedro");
	cout<<p<<"\n";
	********************/

	show(6,8,true,"hola",3.1415);
	show("hola",26,"hello");
	
	string p = join(",","juan","jose","pedro","adrian","pepe","julio");
	cout<<p<<"\n";
	
}
