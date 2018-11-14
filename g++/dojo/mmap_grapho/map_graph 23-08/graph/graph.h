#ifndef _GRAPH_
#define _GRAPH_
template<class T, class R>
class graph
{
	struct node
	{
		T value;
		mmap<T,container> adjacency_list;
		
		void add_adjacency(R relation, const node* node_obj)
		{
			
		}
	};
	
	struct container
	{
		R relation;
		node* nodeObj;
	};	
	
	mmap <T,int> nodes;
	
	public:
	mmap<container>& insert(const T& value)
	{
			
	}
	
	void show_adjacencies() const
	{}
};

#endif