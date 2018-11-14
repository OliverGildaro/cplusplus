#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class wrapper
{
private:
      T* value;
public:
      wrapper(T* value) :value{value} { }

      wrapper(const wrapper<T>&& src)//implementando el constructor de movida
      :value{src.value}
      {
            src.value = nullptr;
            cout << "moved\n";
      }

      wrapper(const wrapper<T>& src) = delete;//eliminando el constructor sobrecargado

      ~wrapper() {delete value; }

      T* get() const {return value;}

      T* operator->() {return value;}
};


struct A
{
      size_t n;

      A(size_t n)
      :n{n} {}

      void print()
      {
            cout << n << "\n";
      }
};


int main(int argc, char const *argv[])
{
      //Ejemplo de wrapper
      // wrapper<A> w {new A{155}};
      // w.get()->print();
      // w->print();

      // auto b = move(w); //ahora b apunta al objeto
      // b->print();

      //Implementando Unique_ptr
      unique_ptr<A> c = make_unique<A>(2048); 
      c.get()->print(); //get es un metodo de memory
      c->print(); //el operador-> sobrecargado ya viene en la clase memory

      unique_ptr<A> d = move(c); //el constructor de movida tiene su implementacion en la clase memory 
      d->print();
      if(c == nullptr)
      {
            cout<<"NULL\n";
      }
      (*d).print();
      d.reset();
}