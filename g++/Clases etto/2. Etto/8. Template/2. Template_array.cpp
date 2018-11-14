#include <cstdio>
#include<iostream>
#include<string>

using namespace std;
template<class T>
struct eq
{
	bool are_equal(const T& a,const T& b)const
	{
		return a==b;
	}
};
template<class T>
struct eq<T*>
{
	bool are_equal(const T* a,const T* b)const
	{
		eq<T> cmp;
		return cmp.are_equal(*a,*b);
	}
};

template<class T>
struct deleter
{
	void free(const T& )
	{}
};
template<class T>//esta es una especializacion
struct deleter<T*>
{
	void free(T* obj)
	{
		delete obj;
	}
};

template<typename T,typename EQ =eq<T>,typename DELETER =deleter<T>>
class array_list
{
	size_t count;
	size_t cap;
	T* items;
public:
	array_list(size_t cap =4)
		:count{0},cap{cap},items{new T[cap]}
	{

	}
	~array_list()
	{
		DELETER d;
		for(auto i=0U;i<count;i++)
		{
			d.free(items[i]);
		}
		delete[] items;
	}
	void push_back(const T& obj)
	{
		if(count==cap)
			resize();
		items[count]=obj;
		count++;
	}
private:
	void resize()
	{
		auto ncap=cap*2;
		auto nitems=new T[ncap];
		for(auto i=0U;i<count;i++)
		{
			nitems[i]=items[i]; 
		}
		cap= ncap;
		delete[] items;
		items=nitems;
	}
public:
	int index_of(const T& obj )const
	{
		EQ eq;
		for(auto i=0U;i<count;i++)
		{
			if (eq.are_equal(obj,items[i]))
				return i;
		}
		return -1;
	}

};
struct CI
{
	string n;
	string city;
};
struct CIeq
{
	bool are_equal(const CI& x,const CI& y)const
	{
		return x.n==y.n && x.city==y.city;
	}
};
struct P
{
	int n;
	~P()
	{
		puts("bye");
	}
};
template<>//sino se pone template<typename T>
struct eq<P>//se pone asi o se pone como lo comentado arriba
{
	bool are_equal(const P&a, const P&b)const
	{
		return a.n==b.n;
	}
};
int main()
{
	array_list<int*>x;
	
	x.push_back(new int{3});
	x.push_back(new int{3});
	x.push_back(new int{3});
	x.push_back(new int{3});
	array_list<P*>ps;
	ps.push_back(new P{1});
	ps.push_back(new P{3});
	int q = 14;
	auto idd=x.index_of(&q);
	cout<<idd<<"\n";

	P d {1};
	auto ide=ps.index_of(&d);
	cout<<ide<<"\n";

}