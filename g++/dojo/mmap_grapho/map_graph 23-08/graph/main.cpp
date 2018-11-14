


auto main() -> int
{
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
	
	node4.add_adjacency(1, node1);
	node4.add_adjacency(2, node2);
	node4.add_adjacency(3, node3);
	
	s.show_adjacencies();
	
	
	
	return 0;
}