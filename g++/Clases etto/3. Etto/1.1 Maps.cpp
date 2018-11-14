#include <map>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <memory>
#include <functional>

using namespace std;

ostream& operator<<(ostream &os, const tuple<string, string, int> &x)
{
    os << get<0>(x) << " " << get<1>(x) << "(" << get<2>(x) << ")"<< endl;
    return os;
}

template<typename T, typename Q, typename R>
void ins(T& m, Q q, R r)
{
    m.insert(make_pair(make_unique<Q>(q), r));
}

void f(int n)
{
    cout << n*n << "\n";
}
using up = unique_ptr<int>;
using mfunc = function<void(int)>;

struct up_hash
{
    size_t operator()(const up &n)const
    {
        return *n;
    }
};

struct up_eq
{
    bool operator()(const up & a, const up &b)const
    {
        return *a == *b;
    }
};

int main(int argc, char const *argv[])
{
    /*map<int, tuple<string, string, int>> ps;
    ps.insert(
        pair<int, tuple<string, string, int>>
            (108954,
            tuple<string, string, int>
            {"juan","calle",1980})
    );
    ps.insert(make_pair(224851, make_tuple("jorge","cortez",1978)));

    ps[4529842] = make_tuple("pamela", "alvarez", 1985);

    for(auto &p:ps)
    {
        cout<<"key: "<<p.first<<" ;value: "<<p.second<<endl;
    }

    // auto &q = ps[12345];
    // cout<<get<2>(q)<<endl;
    // BAD IDEA
    
    auto r = ps.find(224851);
    if (r == ps.end())
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << r->second << "\n";
    }
    // GOOD IDEA

    unordered_map<int, tuple<string, string, int>> qs;
    for (auto & p:ps)
    {
        qs.insert(p);
    }
    cout<<"*******\n";
    for(auto &q:qs)
    {
        cout<<q.first<<" "<<q.second<<endl;
    }*/

    unordered_map<unique_ptr<int>, mfunc, up_hash, up_eq> ms;
    ins(ms,64,[](int p){cout<<p+1<<endl;});
    ins(ms,125,f);
    ms[make_unique<int>(64)](12);

    int m = 200;
    ins(ms, 146,[&m](int n){cout<<m+n<<endl;m++;});
    ms[make_unique<int>(146)](22);
    cout<<m<<endl;
}

/*
    nunca usar operator [] para
    comparar objetos
*/