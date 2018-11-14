#include <iostream>
using namespace std;

c++11

int &a; // lvalue reference
int&& a; // rvalue reference c++11

move semantics
perfect forwarding

struct MyObj
{
    char* p;
    MyObj()
    :p{new char[100000000]}
    {
        cout << "Created\n";
    }
    ~MyObj()
    {
        delete [] p;
        cout <<"Deleted\n";
    }
    MyObj(const MyObj &src)//constructor copia
    :p(new char[100000000])
    {
        for (int i = 0; i < 100000000; ++i)
        {
            p[i] = src.p[i];
        }
        cout << "Copied\n";
    }
    MyObj(MyObj&& src)//constructor de movida
    :p{src.p}
    {
        src.p = nullptr;
        cout<<"moved\n";
    }

    MyObj& operator=(const MyObj &src)
    {
        this->~MyObj();
        p = new char[100000000];
        for (int i = 0; i < 100000000; ++i)
        {
            p[i] = src.p[i];
        }
        cout << "=ed\n";
        return *this;
    }
};

MyObj create()
{
    return MyObj{};
}

struct Heavy
{
    char *x;
    Heavy()
    :x{new char[10'000'000]}
    {}
    ~Heavy()
    {
        delete [] x;
    }
    Heavy(const Heavy& src)
    :x{new char[10'000'000]}
    {
        for (int i = 0; i < 10'000'000; ++i)
        {
            x[i] = src.x[i];
        }
    }
    Heavy(Heavy &&src)
    :x{src.x}
    {
        src.x=nullptr;
    }

    Heavy& operator=(const Heavy &src)
    {
        delete []x;
        x= new char[10'000'000];
        for (int i = 0; i < 10'000'000; ++i)
        {
            x[i] = src.x[i];
        }
        return *this;
    }

    Heavy& operator=(Heavy &&src)
    {
        delete []x;
        x = src.x;
        src.x = nullptr;
        return *this;
    }
};

template <typename T>
void my_swap(T& a, T&b)
{
    T aux = move(a);
    a = move(b);
    b = move(aux);
}

int main(int argc, char const *argv[])
{
    /*MyObj obj;
    obj = create();*/
    Heavy obj;
    Heavy obj2;
    for (int i = 0; i < 1'000'000; ++i)
    {
        my_swap(obj,obj2);
    }
}
/*
    Copy elision es caracteristica para omitir copias innecesarias
    -fno-elide-constructors
    despues se intorducio un nuevo concepto llamado rvalue reference
    construtor de movida
*/