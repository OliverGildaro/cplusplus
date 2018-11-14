#ifndef MMAP_H
#define MMAP_H
#include <iostream>
#include "value_not_found.h"
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
	
	void insert_node(node* &nodo_actual, const K& key,const V& value)
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
		if(current_node->key==key)
		{
			return current_node->value;
		}
		if(current_node->key<key)
		{
			return find(current_node->right,key);
		}
		return find(current_node->left,key);
	}
	const V& operator[](const K& key) const
	{
		return find(root,key);
		
	}

};
#endif