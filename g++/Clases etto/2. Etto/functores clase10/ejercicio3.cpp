
#include <cstdio>
#include<iostream>
#include<string>

using namespace std;

template<class T/*v2*/,class PRED>
void show(const T* arr,size_t n,/*bool(*pred)(const T&)->v2*/ PRED pred)
{
	for(auto i=0U;i<n;i++)
	{
		if(pred(arr[i]))
			cout<<arr[i]<<"\n";
	}
}
bool empieza_con_m(const string& s)
{
	return s[0]=='m';
}
struct empieza_con
{
	char c;
	bool operator()(const string& s)const
	{
		return s[0]==c;
	}
};

int main()
{
	string p[]={"enero","febrero","marzo","abril","mayo"};
	show(p,5,empieza_con_m);
	empieza_con ec{'e'};
	show(p,5,ec);
	puts("xxx");
	show(p,5,[](const string &s)//los conrchetes ;le dicen al compilador que lo que viene a continuacion es una funcion anonima
	{
		return s.length()>=5;
	});
	puts("xxxxxxxx");
	auto n =0U;
	show(p,5,[&n](const auto &s)
	{
		if(s[s.length()-1]=='o')
		{
			n++;
			return true;

		}
		return false;
	});
	cout<<n<<"\n";
}