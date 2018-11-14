#ifndef MMAP_H
#define MMAP_H
#include <iostream>

template<typename K, typename V>
class mmap
{
	struct node
	{
		K key;
		V value;
		node* left;
		node* right;
	};
	node* root;
	size_t size;
	public:
	mmap()
	:root{nullptr},size{0}
	{
	}
	
	void insert_node(node* nodo_actual, const K& key,const V& value)
	{
		if (nodo_actual == nullptr)
		{
			nodo_actual = new node{key, value, nullptr, nullptr};
			size++;
			return;
		}
		if(nodo_actual->key > key)
		{
			insert_node(nodo_actual->left,key,value);
		}
		else if(nodo_actual->key < key)
		{
			insert_node(nodo_actual->right,key,value);
		}
		else
		{
			throw 1;
		}
	}
	
	void insert(const K& key,const V& value)
	{
		insert_node(root, key, value);
	}
	size_t get_size()const
	{
		return size;
	}
	template <typename PROC>
	
	void iterate(PROC p)const
	{
		iterate_deep (p, root);
	}
	template <typename PROC>
	void iterate_deep(PROC p, node* current_node)const
	{
		
	}
	const K& get_maximum_key() const
	{
		throw 1;
	}
	const K& get_minimum_key() const
	{
		throw 1;
	}
	const V& operator[](const K&) const
	{
		throw 1;
	}
};
#endif