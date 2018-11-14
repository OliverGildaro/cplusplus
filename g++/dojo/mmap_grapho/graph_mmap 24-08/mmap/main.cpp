#include "mmap.h"
#include "value_not_found.h"
#include <string>
#include <iostream>

using namespace std;

void test_internal()
{
	mmap<int, string> x;
	
	for (int i = 1500; i < 3000; i++)
	{
		x.insert(i, to_string(i));
		x.insert(1499 - i, to_string(i) + "**********************************************************");
	}
}

void test()
{
	for (int i = 0; i < 100000; i++)
	{
		if (i % 100 == 0) cout << i << "\n";
		test_internal();
	}
}

struct ci
{
	int id;
	string city;
};

template<>
struct default_comparator<ci>
{
	bool operator()(const ci& a, const ci& b)const
	{
		return (a.id<b.id);
	}
};

struct person
{
	string fn;
	string ln;
	int birthyear;
};

ostream& operator<<(ostream& os, const person& p)
{
	return os << p.ln << " " << p.fn << " : " << p.birthyear;
}

ostream& operator<<(ostream& os, const ci& c)
{
	return os << c.id << " "<< c.city;
}

void insert(mmap<ci, person>& ps, int ciPerson, const string& city, const string& name , const string& ln, int by)
{
	ci ciData{ciPerson, city};
	person personData{name,ln,by};
	ps.insert(ciData,personData);
}
auto test_ci_person()
{
	mmap<ci, person> ps;
	
	insert(ps, 1212313, "LP", "Juan", "Lopez", 1960);
	insert(ps, 5634563, "CB", "Gabriel", "Fuentes", 1945);
	insert(ps, 2575673, "PT", "Irving", "Coronel", 1825);
	insert(ps, 2563256, "SC", "Marco", "Baltazar", 2010);
	insert(ps, 7952351, "CH", "Paolo", "Moscoso", 1979);
	insert(ps, 8545345, "LP", "Cristelh", "Miranda", 2000);
	insert(ps, 3452345, "OR", "Neyver", "Fulguera", 2012);
	insert(ps, 5496853, "TJ", "Romulo", "Rojas", 1932);
	
	auto& x = ps[ci { 8545345, "LP" }];
	cout << x << "\n";
	
	cout << "*************\n";
	
	int n = 0;
	ps.iterate([&n](const ci& x, const person& p)
	{
		cout << x << "; " << p << "\n";
		n++;
	});
	
	cout << "People count: " << n << "\n";
}

auto main() -> int
{
	//test();
	
	test_ci_person();
	
	// try
	// {
		// mmap<int, string> m1;
		// m1.insert(20, "veinte");
		// m1.insert(10, "diez");
		// m1.insert(40, "cuarenta");
		// m1.insert(0, "cero");
		// m1.insert(30, "treinta");
		// m1.insert(60, "sesenta");
		// m1.insert(50, "cincuenta");
		
		// m1.iterate([](auto& a, auto& b)
		// {
			// cout << a << "; " << b << "\n";
		// });
		
		// cout << "Count: " << m1.get_size() << "\n";
		
		// cout << "Maximum key: " << m1.get_maximum_key() << "\n";
		
		// auto& min = m1.get_minimum_key();
		// cout << "Minimum key: " << m1.get_minimum_key() << "\n";
		
		// cout << "Minimum value: " << m1[min] << "\n";
		
		// cout << "Value: " << m1[25] << "\n";
		
	// }
	// catch (const value_not_found<int>& e)
	// {
		// cout << "Value not found for key: " << e.get_key() << "\n";
	// }
	// catch (const std::exception& e)
	// {
		// cout << "Exception: " << e.what() << "\n";
	// }
	
	
	return 0;
}