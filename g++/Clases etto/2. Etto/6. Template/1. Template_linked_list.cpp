
#include <iostream>

using namespace std;

template <typename T>
class node
{
private:
      T value;
public:
      node<T>* next;
public:
      node(const T& value)
      :value{value}, next{nullptr} { }
      ~node() { }

      T get_value()
      {
            return value;
      }
};

template <typename T>
class linked_list
{
private:
      node<T>* first;
      node<T>* last;
      size_t count;

public:
      linked_list(/* args */)
      :first{nullptr}, last{nullptr}, count{0} { }
      ~linked_list() { }

      void push_back(const T& value)
      {
            node<T>* new_node = new node<T>{value};
            if(first == nullptr)
            {
                  first = last = new_node;
            }
            else
            {
                  last->next = new_node;
                  last = new_node; 
            }
            count++;
      }

      void iterate(void(*function)(int))
      {
            node<T>* cursor = first;
            for(size_t i = 0U; i < count; i++)
            {
                  function(cursor->get_value());
                  cursor = cursor->next;
            }
            
      }

      template <typename PROC>
      void iterate(PROC p)
      {
            node<T>* cursor = first;
            for(size_t i = 0U; i < count; i++)
            {
                  p(cursor->get_value());
                  cursor = cursor->next;
            }
            
      }
};

void show_int(int value)
{
      cout << "Value: " << value << "\n"; 
}

template <typename T>
void show(const T& value)
{
      cout << "Value: " << value << "\n";
}

int main()
{
	linked_list<int> x;//hay que especificar en el caso de que sea un template de una clase <int>
	x.push_back(16);
	x.push_back(10);
	x.push_back(8);
	x.push_back(20);
	x.push_back(10);
	x.iterate(show_int);
	x.iterate(show<int>);

	linked_list<string> y;//hay que especificar en el caso de que sea un template de una clase <int>
	y.push_back("hey");
	y.push_back("10");
	y.push_back("8");
	y.push_back("20");
	y.push_back("hola");
	y.iterate(show<string>);

}