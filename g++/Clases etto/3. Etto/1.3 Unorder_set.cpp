#include <unordered_set>
#include <iostream>

using namespace std;

struct alumno
{
    string nombre;
    int id;
};

struct alumno_hash
{
    size_t operator()(const alumno &s) const
    {
        hash<string> hs;
        return s.id*17+hs(s.nombre);
    }
};

struct alumno_eq
{
    bool operator()(const alumno & a, const alumno &b)const
    {
        return tie(a.nombre,a.id)==tie(b.nombre,b.id);
    }
};

int main(int argc, char const *argv[])
{
    /*unordered_set<string> ms;
    ms.insert("alvaro");
    ms.insert("romulo");
    ms.insert("pablo");
    ms.insert("daniela");
    ms.insert("vivian");
    for(auto& m:ms)
        cout<<m<<endl;*/
    unordered_set<alumno, alumno_hash, alumno_eq> al2;
    al2.insert(alumno{"jose", 123});
    al2.insert(alumno{"maria", 127});
    al2.insert(alumno{"jesus", 342});

    for(auto& a:al2)
    {
        cout << a.nombre <<" "<<a.id<<endl;
    }

    auto it = al2.find(alumno{"jesus",342});
    if (it==al2.end())
    {
        cerr<<"Not Found\n";
    }
    else
    {
        cout << "Found\n";
    }
}