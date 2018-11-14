#include <cstdio>
#include <iostream>

using namespace std;

struct X
{
	X() {puts("i am x");}
};

struct Y
{
	int n;
	Y(int n):n{n}
	{
		puts("i am y");
	}
};

struct Z: public X, public Y
{
	Z():X{},Y{1240} { }
};

int main()
{
	Z z;
	cout<<z.n<<"\n";
}