#include <iostream>
#include <memory>
#include <cstdio>

using namespace std;

template <typename T>
class wrapper
{
      T *item;
public:
      wrapper(T *item):item{item} { } // constructor parametrizado

      wrapper(wrapper<T>&& src) //constructor sobrecargado
      :item{src.item}
      {
            src.item =nullptr;
            cout<<"Moved\n";
      }

      wrapper(const wrapper<T>&) = delete; //eliminando el constructor sobrecargado

      ~wrapper() {delete item;}

      T* get() const {return item;}

      T* operator->() {return item;}
};

struct A
{
    int n;
    A(int n):n(n) { }

    ~A() {cout<< "BYE\n";}
    void print() const
    {
        cout<<n<<endl;
    }
};

struct closer
{
    void operator()(FILE *f)
    {
        if(f == nullptr) return;
        fclose(f);
        cout<<"BYEfile\n";
    }
};

class Point
{
    unique_ptr<A> x;
    unique_ptr<A> y;
public:
      Point(int x, int y)
      :x{new A{x}}, y{new A{y}}
      {
            s();
      }
      ~Point() { }
      void print() const
      {
            x->print();
            y->print();
      }
      void s()
      {
            throw nullptr;
      }
};

int main(int argc, char const *argv[])
{
    unique_ptr<FILE,closer> ar{fopen("abc.txt","w")};
    fputs("hello",ar.get());
    fputs("world", ar.get());


    try{
        Point q{10,25};
        q.print();
    }
    catch(...){cout<<"Error\n";}
}
/*las variables de stack que parecen punteros 
se llaman smart pointers
    variable de stack
    implementa el operador flechita
    Implementa una politica de manejo de memoria
al incluir MEMORY
se incluyen 4 pointers
unique pointer igual al wrapper
shared_ptr 
weak_ptr
auto_ptr deprecated
tiene un constructor make_unique<A>()
*/