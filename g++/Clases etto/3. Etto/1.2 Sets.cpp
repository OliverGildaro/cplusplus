/*
    los sets contienen elementos del mismo tipo
    los elementos se pueden iterar
    se puede ver si un elem esta en el set
    es un arbol binario de busqueda equilibrado
*/
#include <set>
#include <iostream>
#include <tuple>

using namespace std;

struct alumno
{
    string nombre;
    int id;
};

struct less_alumno
{
    bool operator()(const alumno &a, const alumno &b)const
    {
        return a.nombre<b.nombre;
    }
};

int main(int argc, char const *argv[])
{
    /*set<string> ds;
    ds.insert("irving");
    ds.insert("paolo");
    ds.insert("rai");
    ds.insert("marco");


    for(const string &e:ds)
    {
        cout<<e<<"\n";
    }
    cout<<"..............\n";
    set<string>::iterator it = ds.find("marco");
    if (it == ds.end())
    {
        cerr<<"NotFound"<<endl;
    }
    else
    {
        cout<<*it<<endl;
    }
    size_t a = ds.erase("diego");
    cout<<a<<endl;*/
    auto f = [](auto& a, auto& b)
    {
        return tie(a.id,a.nombre)<tie(b.id,b.nombre);
    };
    set<alumno, decltype(f)> al{f};
    al.insert(alumno{"juan",123});
    al.insert(alumno{"jorge",642});
    al.insert(alumno{"pedro",456});
    al.insert(alumno{"maria",456});

    for(auto &a:al)
    {
        cout<< a.nombre<<" "<<a.id<<endl;
    }
}