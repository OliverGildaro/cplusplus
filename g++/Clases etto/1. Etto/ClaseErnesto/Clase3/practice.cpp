#include <iostream>
#include <cstring>
using namespace std;

class stringlinkedlis
{
	struct Node
	{
		size_t size;
		char* name;
		Node* next;		
	};

	first = nullptr;
	last = nullptr;
	count = 0;

	stringlinkedlis()
	{

	}

	void push_back(const char* p)
	{
		auto len = strlen(p);
		auto nn = new char[len+1];
		memcpy(nn,p,len+1);

		Node* node = new Node{len,nn,nullptr};
		count++;

		if(first==nullptr)
		{
			first = last = node;
		}
		last->next =  node;
		last = node;
	}
};

int main()
{
	stringlinkedlis s;
	s.push_back("hello");
	s.push_back("world");
}	