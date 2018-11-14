#include <iostream>
#include <cstdio>

template <int N>//un template recibe tipos, este template recibira solo enteros
void stars()
{
	for (int i = 0; i < N; i++)
	{
		printf("*");
	}
	puts("\n");
}
int main()
{
	constexpr int r = 5;//convierte a r en una variable de tipo constante
	stars<r> ();
	puts("HELLO\n");
	stars<6> ();

}