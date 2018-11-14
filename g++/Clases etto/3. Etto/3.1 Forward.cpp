#include <iostream>

using namespace std;

void print(const string &s)
{
    cout<<s<<"\n";
}

template <typename PROC, typename T>
void invoke(T&& src, PROC p)
{
    cout << "***\n";
    p(forward<T>(src));
    cout<< "***\n";
}

void inc(int &n)
{
    n++;
}

void print2(int r)
{
    cout << r << "\n";
}

/*void testA(A&& a)
{
    A x = a;
}
este caso lo contempla solamente el forward y es por 
eso que es necesario
*/
int main(int argc, char const *argv[])
{
    invoke("hola",print);
    int p=18;
    invoke(p,inc);
    cout<<p<<endl;
    invoke(14,print2);
}
/*
    casteo a tipos de cosas esperados
*/