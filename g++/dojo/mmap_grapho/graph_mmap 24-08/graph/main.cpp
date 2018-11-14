#include <iostream>
#include <string>
#include "graph.h"

using namespace std;


auto main() -> int
{
	try{
	graph<string, int> s;
	
	auto& node1 = s.insert("hola");
	auto& node2 = s.insert("mundo");
	auto& node3 = s.insert("programadores");
	auto& node4 = s.insert("c++");
	
	node1.add_adjacency(4, node2);
	node1.add_adjacency(8, node3);
	
	node2.add_adjacency(0, node2);
	node2.add_adjacency(2, node4);
	
	node3.add_adjacency(10, node1);
	
	node4.add_adjacency(14, node1);
	node4.add_adjacency(25, node2);
	node4.add_adjacency(30, node3);
	
	cout << "is node 2 adjacent to node 1? "
	     << node2.is_adjacent(node4) << "\n";
	
	cout << "Getting relation\n" ;
	cout << s["c++"].get_relation("programadores") << "\n";
	
	s.iterate([](auto& val, auto& node)
	{
		cout << "NODE: " << val << "\n";
		node.iterate_adjacencies([](auto& node, auto& rel) 
		{
			//cout << "* Rel: " << rel << "\n";
			cout << "* " << node.get_value() << "; Rel: " << rel << "\n";
		});
	});
	
	
	}
	catch(const std::exception& e){
				std::cout << e.what() <<"\n";
	}
	catch(int n )
	{
		std::cout << n << "\n";
	}
	
	return 0;
}