#include <iostream>
#include <cstring>
using namespace std;

class stringlinkedlist
{
	struct Node//con struct todo es publico por defecto dentro del struct
	{
		size_t len;
		char* s;
		Node* next;

	};

	Node* first;
	Node* last;
	size_t count;

	public:
		stringlinkedlist():first{nullptr}, last{nullptr}, count{0}
		{

		}

		~stringlinkedlist(){
			Node* node = first;

			while(node!=nullptr)
			{
				Node* next = node->next;
				delete []node->s;
				delete node;

				node = next;
			}
		}

		stringlinkedlist(const stringlinkedlist&) = delete;
		
		void operator=(const stringlinkedlist&) = delete;

		void push_back(const char* p)
		{
			auto len = strlen(p);
			auto nn = new char[len+1];
			memcpy(nn,p,len+1);

			Node* node = new Node{len,nn,nullptr};
			count++;

			if(first == nullptr)
			{
				first = last = node;
				return;
			}
			last->next = node;
			last = node;
			
		}

		void show() const
		{
			Node* aux = first;
			while(aux)
			{
				cout<<aux->s<<endl;
				aux = aux->next;
			}
		}
	
};


int main()
{
	stringlinkedlist s;

	s.push_back("hello");
	s.push_back("world");
	s.push_back("c++");


	s.show();
}

//EJERCICIO
//*VOLVER LA LISTA DOBLEMENTE ENLAZADA
//*IMPLEMENTAR size_t erase(const char* p);
//*IMPLEMENTAR constructor copia
//*IMPLEMENTAR operator=
