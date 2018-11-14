#include <iostream>
#include <exception>
#include <memory>
#include <vector>
#include <array>
#include <list>

using namespace std;


class f_exception : public exception
{
private:
      string text;
public:
      f_exception() 
      :text{"error"} {}
      ~f_exception() { }

      string what()
      {
            return text;
      }
};

template <typename T>
void show(const T &x)
{
      for (auto& i:x) {cout << i << "\n";}
}

struct P
{
      int n;
      ~P() {cout << "Bye\n";}
};

int main(int argc, char const *argv[])
{
      //ARRAY: debe definirse el tamanio del array, tamanio limitado
      // array<int, 3> s;
      // s[0] = 125;
      // s[1] = 14;
      // s[2] = 248;

      // for (array<int, 3>::iterator i = s.begin(); i != s.end(); ++i)
      // {
      //       cout << *i << "\n";
      // }

      // show(s);


      //VECTOR: no hace falta definir el tamanio que ademas es ilimitado
      // vector<int> p = {6,8,4,2,1,9};

      // p.push_back(12);
      // size_t len = p.size();

      // try
      // {
      //     for (size_t i = 0U; i < len+1; ++i)
      //     {
      //         if(i == len)
      //             throw f_exception{};
      //         cout << p[i] << "\n";
      //     }
      // }
      // catch(const exception &ex)
      // {
      //     cout << ex.what() << endl;
      // }

      // show(p);

      // for(auto i = p.begin()+1; i!=p.end()-1;++i)
      // {
      //     cout << "* "<<*i<<endl;
      // }


      //LIST
      // list<string> dd = {"Tuesday", "Wednesday", "Thursday"};

      // dd.push_back("Friday");
      // dd.push_front("Monday");

      // cout << dd.back() << "\n";
      // cout << dd.front() << "\n";

      // dd.pop_back();//elimina el ultimo elemento

      // cout << dd.back() << "\n";
      // cout<< "<<<<<<<<<<<<<\n";
      // // show(dd);
      // cout<< "<<<<<<<<<<<<<\n";
      
      // for(auto i = dd.begin(); i != dd.end(); i++)
      // {
      //       cout << *i << "\n";
      // }
      

      //VECTOR - MEMORY
      vector<unique_ptr<P>> x; //puntero a objeto P
      P *paux = new P{10}; //instanciando un objeto P
      x.emplace_back(paux);
      x.emplace_back(new P{15});

      auto& q = x[1];
      cout << q->n << endl;

      vector<reference_wrapper<P>> rx;
      for(auto &i:x)
      {
            rx.push_back(*i);
      }
      for(auto &i:rx)
      {
            cout<<i.get().n<<endl;
            // cout << ((P&)i).n <<endl;
      }



      // std::vector<int(*)(int ,int)> ops;
      // ops.push_back([](int a,int b){return a+b;});
      // ops.push_back([](int a,int b){return a-b;});
      // for(auto& op:ops)
      // {
      //     cout << op(6,4)<<endl;
      // }
}
// sin impotar el contexto se puede hacer un cbegin y un cend

// vector          vs          lists
// el vector no admite wrappear las referencias 
// por lo que se utiliza el reference_wrapper
