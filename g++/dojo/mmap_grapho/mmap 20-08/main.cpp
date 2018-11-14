#include "mmap.h"
#include "value_not_found.h"
#include <string>
#include <iostream>

using namespace std;

auto main() -> int
{
	try
	{
		mmap<int, string> m1;
		m1.insert(20, "veinte");
		m1.insert(10, "diez");
		m1.insert(40, "cuarenta");
		m1.insert(0, "cero");
		m1.insert(30, "treinta");
		m1.insert(60, "sesenta");
		m1.insert(50, "cincuenta");
		
		m1.iterate([](auto& a, auto& b)
		{
			cout << a << "; " << b << "\n";
		});
		
		/*cout << "Count: " << m1.get_size() << "\n";
		
		cout << "Maximum key: " << m1.get_maximum_key() << "\n";
		
		auto& min = m1.get_minimum_key();
		
		cout << "Minimum value: " << m1[min] << "\n";
		
		cout << "Value: " << m1[25] << "\n";*/
		
	}
	catch (const value_not_found<int>& e)
	{
		cout << "Value not found for key: " << e.get_key() << "\n";
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << "\n";
	}
	
	
	return 0;
}