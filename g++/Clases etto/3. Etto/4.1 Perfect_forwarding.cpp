#include <iostream>

using namespace std;

struct A
{
    A(){cout<<"ctor\n";}
    ~A(){cout<<"bye\n";}
    A(const A& x){cout<<"copy\n";}
    A& operator=(const A& x)
    {
        cout<<"=\n";
        return *this;
    }
    A(A&& x)
    {
        cout<<"MoveCtor\n";
    }
    A& operator=(A&& x)
    {
        cout<<"Move=\n";
        return *this;
    }
};

struct B
{
    A a;
    /*B(const A& x)
    :a{x}{cout<<"ctorB\n";}
    B(A&& x):a{move(x)}
    {
        cout<<"MoveCtorB\n";
    }*/
    template <typename T>
    B(T&& x)
    :a{forward<T>(x)}
    {
        cout<<"ctorB\n";
    }
    /*collapsing rules
    T& & = T&
    T& && = T&
    T&& & = T&
    T&& && = T&&*/
};
/*forward sabe la naturaleza de la llamada y
llama a su constructor copia o movida*/
int main(int argc, char const *argv[])
{
    A a;
    B b{a};
    B c{A{}};
    cout<<":P\n";
    return 0;
}