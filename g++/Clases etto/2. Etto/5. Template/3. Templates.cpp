#include <iostream>

using namespace std;

template <class T, class U>
auto sum (const T &a, const U &b)//2. llegan los objetos construidos
{
	return a+b;//3. no se puede sumar los objetos, llama a operator+
}

struct N
{
	int n;

      N(int n):n{n} //1. se construyen los objetos
      {
            cout << "hola const " << n << "\n";
      }

	N operator+(const N& src) const//4. como parametro llega el segundo objeto
	{
		return N{n+src.n};//5. realiza la suma, llama al constructor y devuelve el objeto
	}
};
int main()
{
      N x = sum(N{10},N{11});//6. el objeto se asigna a x
      cout << x.n << "\n";
}