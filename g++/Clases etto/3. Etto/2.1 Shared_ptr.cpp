#include <iostream>
#include <memory>

using namespace std;

struct A
{
    int n;
    A(int n):n(n) { }

    ~A() {cout<< "BYE\n";}

    void print() const {cout<<n<<endl;}
};

void p(const A &x)
{
    x.print();
}

struct mama_de_marco;

struct marco
{
    shared_ptr<mama_de_marco> mdm;
    ~marco(){cout<<"No te vayas MAMA\n";}
    void hi(){cout<<"Hola mama\n";}
};

struct mama_de_marco
{
    weak_ptr<marco> hijo;
    ~mama_de_marco(){cout<<"Adios Marco\n";}
};

int main(int argc, char const *argv[])
{
    auto m = make_shared<marco>();
    auto mdm = make_shared<mama_de_marco>();
    m->mdm = mdm;
    mdm -> hijo = m;
//     mdm -> hijo.lockdmotw() -> hi();



    // A* a = new A{1};
    // shared_ptr<A> ap{a};
    // shared_ptr<A> bp = ap;
    // cout<<ap.use_count()<<endl;
}
    // el shared pointer ademas de guardar el puntero
    // guarda un contador de punteros al mismo
    // cuando hay punteros de ida y vuelta no se elimina la instancia
