#include <iostream>
using namespace std;

template <class T,class U>
auto sum (const T &a, const U &b)
{
	return a+b;
}

int main()
{
	auto p = sum(8, 10);
	cout << p << "\n";

	double q = sum(3.14, 8.16);
	cout << q << "\n";

	auto m = sum(string{"hola"}, string{" mundo"});//castea el const char* a string
	cout << m << "\n";

	auto z = sum<string,string>("hola", " mundo");//le decimos a sum que va a recibir dos strings
	cout << z << "\n";
}