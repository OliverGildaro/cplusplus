#include <cstdio>
#include<iostream>
#include<string>

using namespace std;

template <class T>
struct eq
{
	bool are_equal(const T& a,const T& b)const
	{
		return a == b;
	}
};

template <typename T, typename EQ = eq<T>>
class array_list
{
	size_t count;
	size_t cap;
	T* items;

public:
	array_list(size_t cap = 4)//si no ponemos el cuatro la primera linea del main no compila
	:count{0}, cap{cap}, items{new T[cap]}
	{

	}

	~array_list()
	{
		delete[] items;
	}

	void push_back(const T& obj)
	{
		if(count == cap)
			resize();
		items[count] = obj;
		count++;
	}

private:
	void resize()
	{
		auto ncap=cap*2;
		auto nitems=new T[ncap];
		for(auto i = 0U; i < count; i++)
		{
			nitems[i] = items[i]; 
		}
		cap = ncap;
		delete[] items;
		items = nitems;
	}

public:
	int index_of(const T& obj )const
	{
		EQ eq;
		for(auto i = 0U; i < count; i++)
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
	bool are_equal(const CI& x, const CI& y) const
	{
		return x.n == y.n && x.city == y.city;
	}
};

int main()
{
	array_list<int>x;

	array_list<string>y;
	y.push_back("hola");
	y.push_back("hi");
	y.push_back("esta");
	y.push_back("aqui");

	x.push_back(15);
	x.push_back(18);
	x.push_back(45);
	x.push_back(5);
	x.push_back(2);

	array_list<CI,CIeq>q{2};
	q.push_back(CI{"7515142","lp"});
	q.push_back(CI{"12423525","lp"});
	q.push_back(CI{"h2143424","lp"});

	auto pos =x.index_of(2);
	if(pos!=-1)
		cout<<"POS "<<pos<<"\n";
	else
		cout<<"not found\n";

	auto posq =q.index_of(CI{"7515142","lp"});
	if(posq!=-1)
		cout<<"POS "<<posq<<"\n";
	else
		cout<<"not found\n";
}