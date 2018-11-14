#ifndef _GRAPH_
#define _GRAPH_

#include "mmap.h"

template<class T, class R>
class graph
{
	struct node
	{
		T value;
		mmap<const node*, R> node_map;
		graph& my_graph; 
		
		node(graph& p_graph,const T& value)
		:value{value},my_graph{p_graph}
		{
			
		}
		
		//node(const node&) = delete;
		//con esto hacemos que el nodo sea siempre referenciado y no exista un constructor copia
		
		void add_adjacency(const R& relation, const node& new_node)
		{
			node_map.insert(&new_node, relation);
		}			
		
		bool is_adjacent(const node& nodo) const
		{
			try
			{
				node_map[&nodo];
				return true;
			}
			catch(value_not_found<const node*> &)
			{
				return false;
			}
			
		}
		
		const R& get_relation(const T& value) const
		{
			try{
				const node& aux_node = my_graph[value];
				return node_map[&aux_node];
			}catch(const std::exception& e){
				std::cout << e.what() <<"\n";
			}
			
			
		}
		
		template<typename PROC>
		void iterate_adjacencies(PROC proc) const
		{
			node_map.iterate([proc](const node* n, R rel){
				proc(*n,rel);//cambia el tipo de dato del * a referencia
			});
			
		}
		const T& get_value() const
		{
			return value;
		}		
		
		
		
	};
	
	mmap<T, node> nodes;
	public:
	node& insert(const T& src)
	{
		
		return nodes.insert(src,node{*this,src});
	}
	
	const node& operator[](const T& value) const
	{
		return nodes[value];
	}
	
	template <typename FUNC>
	void iterate(FUNC func) const
	{
		nodes.iterate(func);
	}
	
};

#endif