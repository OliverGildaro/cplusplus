#ifndef MMAP_H
#define MMAP_H
#include <iostream>
#include "value_not_found.h"
template<typename T>
struct default_comparator
{
	bool operator()(const T& a,const T& b)const
	{
		return a<b;
	}
	
};



template<
	typename K, 
	typename V, 
	typename COMPARATOR = default_comparator<K>>
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
	COMPARATOR cmp;
	
	size_t size;
	public:
	mmap()
	:root{nullptr},size{0}
	{
	}
	~mmap()
	{
		node* aux=root;
		iterate_destroy(root);
	}
	void iterate_destroy(node* nodo_actual)
	{
		if (nodo_actual == nullptr)
		{
			return;
		}
		iterate_destroy(nodo_actual->left);
		iterate_destroy(nodo_actual->right);
		delete nodo_actual;
		
		
	}
	
	V& insert_node(node* &nodo_actual, const K& key,const V& value)
	{
		if (nodo_actual == nullptr)
		{
			nodo_actual = new node{key, value, nullptr, nullptr};
			size++;
			return nodo_actual->value;
		}
		
		if(cmp(key, nodo_actual->key))
		{
			return insert_node(nodo_actual->left,key,value);
		}
		else if(cmp(nodo_actual->key, key))
		{
			return insert_node(nodo_actual->right,key,value);
		}
		else
		{
			throw 2;
		}
	}
	
	V& insert(const K& key,const V& value)
	{
		 return insert_node(root, key, value);
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
		if(current_node == nullptr)
		{
			return;
		}
		iterate_deep(p, current_node->left);
		p(current_node->key, current_node->value);
		iterate_deep(p, current_node->right);
		}
	const K& get_maximum_key() const
	{
		node* aux = root;
		while(aux!=nullptr)
		{
			if(aux->right == nullptr)
			{
				return aux->key;
			}
			aux = aux->right;
		}
		throw 1;
	}
	const K& get_minimum_key() const
	{
		node* aux = root;
		while(aux!=nullptr)
		{
			if(aux->left == nullptr)
			{
				return aux->key;
			}
			aux = aux->left;
		}
		throw 1;
	}
	const V& find(const node* current_node,const K& key)const
	{
		if(current_node==nullptr)
		{
			throw value_not_found<K>{key};
		}
		if(cmp(current_node->key,key))
		{
			return find(current_node->right,key);
		}
		if(cmp(key,current_node->key))
		{
			return find(current_node->left,key);
		}
		return current_node->value;
	}
	const V& operator[](const K& key) const
	{
		return find(root,key);
	}

};
#endif