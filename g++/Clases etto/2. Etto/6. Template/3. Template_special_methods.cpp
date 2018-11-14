#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

template <int N>
void asterisc()
{
      printf("*");
      asterisc<N-1>();
}

template<>
void asterisc<0>()
{
      cout << "^^\n";
}   

int main()
{
	asterisc<6> ();
	std::cout << "hola";
	asterisc<4> ();
	std::cout << "mundo" <<" \n";
      asterisc<0> ();
}