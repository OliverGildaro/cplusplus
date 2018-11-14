#include <iostream>
#include "lib_object.h"
#include "lib_array_list.h"
#include "lib_integer.h"
#include "lib_string.h"
#include "lib_rawstring.h"
#include "lib_double.h"

using namespace std;

void test()
{
	lib_array_list objs;
	
	objs.add(new lib_rawstring("Hello Friend"));	
	objs.add(new lib_string("Hello Friend"));
	objs.add(new lib_string("World Cruel"));
	objs.add(new lib_string("Yeah! its "));
	objs.add(new lib_string("AAAA"));
	objs.add(new lib_integer(25));
	objs.add(new lib_integer(60));
	objs.add(new lib_double(3.14156926539));
	objs.add(new lib_rawstring("Hello Friend"));	
	objs.add(new lib_string("Hello Friend"));
	objs.add(new lib_string("World Cruel"));
	objs.add(new lib_string("Yeah! its "));
	objs.add(new lib_string("AAAA"));
	objs.add(new lib_integer(25));
	objs.add(new lib_integer(60));
	objs.add(new lib_double(3.14156926539));
	objs.add(new lib_rawstring("Hello Friend"));	
	
	lib_array_list* objs2 = new lib_array_list();
	objs2->add(new lib_rawstring("Hello Friend"));	
	objs2->add(new lib_string("Hello Friend"));
	objs2->add(new lib_string("World Cruel"));
	objs2->add(new lib_string("Yeah! its "));
	objs2->add(new lib_string("AAAA"));
	objs2->add(new lib_integer(25));
	objs2->add(new lib_integer(60));
	objs2->add(new lib_double(3.14156926539));
	objs2->add(new lib_rawstring("Hello Friend"));	
	objs2->add(new lib_string("Hello Friend"));
	objs2->add(new lib_string("World Cruel"));
	objs2->add(new lib_string("Yeah! its "));
	objs2->add(new lib_string("AAAA"));
	objs2->add(new lib_integer(25));
	objs2->add(new lib_integer(60));
	objs2->add(new lib_double(3.14156926539));
	objs2->add(new lib_rawstring("Hello Friend"));	
	
	objs.add(objs2);
}

int main()
{
	/*lib_array_list objs;
	
	objs.add(new lib_string("Hello Friend"));
	objs.add(new lib_string("World Cruel"));
	objs.add(new lib_string("Yeah! its "));
	objs.add(new lib_string("AAAA"));
	objs.add(new lib_integer(25));
	objs.add(new lib_integer(60));
	objs.add(new lib_double(3.14156926539));
	
	auto len = objs.length();
	cout << "Tamano de la lista: " << len << endl; 
	for (auto i = 0U; i < len; i++)
	{
		cout << objs.get(i).to_string().data() << "\n";
	}

	lib_double p { 3.14156926539};
	lib_string p1{"25"};
	lib_integer p2{0x41414141}; 
	
	lib_rawstring p3 { "Hello" };
	
	auto pos = objs.find(p);
	auto pos1 = objs.find(p1);
	auto pos2 = objs.find(p2);
	auto pos3 = objs.find(p3);
	
	cout << "Position: " << pos << "\n";
	cout << "Position: " << pos1 << "\n";
	cout << "Position: " << pos2 << "\n";
	cout << "Position: " << pos3 << "\n";
	return 0;
	*/
	
	for (int i = 0; i < 1000000000; i++)
	{
		if (i % 10000000 == 0)
			cout << i << "\n";
		
		test();
	}
}