#include<iostream>
#include<string>

using namespace std;

template <typename A, typename B, typename C>
struct Test
{
	A a; B b; C c;
	void show () const {cout << a << " " << b << " " << c << "\n";}
};

template <typename X>
struct Test<int, X, int>
{
	int x ; X y ; int z;
	void show() const {cout << (x+z) << " " << y << "\n";}
};

template<>
struct Test<int, int, int>
{
	string s;
	void print()const {cout << s << "\n";}
};

int main()
{
	Test<int, int, string> test{1, 6, "h"};
	test.show();
	Test<int, string, int> test2{1, "x", 20};
	test2.show();
	Test<int, float, int> test3{1, 3.14, 20};
	test3.show();
	Test<int, int, int> test4{"hola"};
	test4.print();
}