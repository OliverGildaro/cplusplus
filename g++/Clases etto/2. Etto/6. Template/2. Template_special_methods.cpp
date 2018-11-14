#include <iostream>

using namespace std;

template <typename T>
void Say_something(const T& value)
{
      cout << value << "\n";
}

template <>
void Say_something <float>(const float& value)
{
      puts("specialization");
      cout << value << "\n";
}

int main()
{
	Say_something<int> (6);
      puts("");

	Say_something<float> (3.14);
      puts("");

	Say_something<string> ("hola");
      puts("");

	Say_something((float)8);
      puts("");
}