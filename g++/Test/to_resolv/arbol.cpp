# include <iostream>
# include <string>
# include <cstring>
# include <memory>
using namespace std;

//Hace tiempo implementamos un TRIE en C.
//Implementarlo a manera de mapa en C++:
template<class T>
struct TrieNode
{
    T second;
    bool value =false;
    TrieNode<T>* children[26];
    TrieNode() 
    {
        memset(children, 0, 26*sizeof(TrieNode<T>*));
    }
    TrieNode(const TrieNode& a)
    {
        second =a.second;
        value=a.value;
    }
    void operator=(const TrieNode& a)
    {
        second=a.second;
        value=a.value;
    }
    bool operator==(const TrieNode<T>* b) const
    {
        return second == b->second;
    }
    bool operator==(const TrieNode<T>& b) const 
    {
        return second == b.second;
    }


};
    
template<class T>
struct TrieMapIterator
{
    TrieNode<T>* root;
    size_t len;
    size_t position;
    size_t index=0;
    T value;
    TrieNode<T>** positions=nullptr;
    TrieNode<T>* pos=nullptr; 
    TrieMapIterator(){}
    TrieMapIterator(TrieNode<T>* n, size_t len, size_t p)
    :root{n}, len{len}, position{p} 
    {}
    TrieMapIterator(TrieNode<T>* n, size_t len, size_t p,const T& a)
    :root{n}, len{len}, position{p}, value{a} 
    {
        setpositions();
        pos = find(a);
        freeMemory();
    }
    void setpositions_r(TrieNode<T>* n, TrieNode<T>**& p)
    {
        if(n->value)
        {
            p[index++] = n;
            return; 
        }
        for(int i=0; i<26; ++i)
        {
            if(n->children[i]!=0)
            {
                setpositions_r(n->children[i], p);
            }
        }
    }
    void setpositions()
    {
        positions = new TrieNode<T>* [len+1];
        setpositions_r(root, positions);
        pos = positions[position++];
        positions[index]=nullptr;
    }
    const TrieMapIterator operator++()
    {
        pos = positions[position++];
        if(pos==nullptr)
        {
            freeMemory();
        }
        return *this;
    }
    bool operator!=(const TrieMapIterator& s) const
    {
        return pos!=s.pos;
    }
    bool operator==(const TrieMapIterator& s) const
    {
        if(pos==nullptr && s.pos==nullptr) return 1;
        if(pos!=nullptr && s.pos!=nullptr)
        {
            if(pos->second == s.pos->second) return 1;
        }
        return 0;
    }
    const TrieNode<T>& operator*() const 
    {
        return *pos;
    }
    void freeMemory()
    {
        delete[] positions;
        positions=nullptr;
    }

    TrieNode<T>* find(const T& a) //const T& s) const
    {
        for(int i=0; i<len;++i)
        {
            if(positions!= nullptr && positions[i]->second==a)
            {
                return positions[i];
            }
        }
        return positions[len+1];
    }
    TrieNode<T>* operator->()
    {
        return pos;
    }

};
template<class T>
struct key_value
{
    string first;
    T second;
    key_value(){}
    key_value(const string& f, const T& v)
    : first{f}, second{v} {}
    void operator=(const key_value<T>& a)
    {
        first=a.first;
        second=a.second;
    }
};


template <typename T>
class trie
{
    TrieNode<T> root;
    size_t lentrie=0;
    key_value<T> pair;
    static void set_data(TrieNode<T>& n, const T& value)
    {
        n.second = value;
        n.value = true;
    }
    void insert(TrieNode<T>& n, const string& key, const T& value, int indexString)
    {
        if(!key[indexString])
        {
            set_data(n, value);
            lentrie++;
            return;
        }
        auto index = key[indexString]-'a';
        auto& e = n.children[index];
        if(e==nullptr)
        {
            e = new TrieNode<T>();
        }
        insert(*e, key, value, ++indexString);
    }
    T& find_data(TrieNode<T>& n, const string& key, int indexString)
    {
        if(key[indexString]==0) return n.second;
        auto index = key[indexString]-'a';
        auto e = n.children[index];
        if(e==nullptr) throw "Data not found";
        return find_data(*e, key, ++indexString);
    }


    T& insert_value(TrieNode<T>& n, const string& key, int indexString)
    {
        if(!key[indexString])
        {
            lentrie++;
            n.value=true;
            return n.second;
        }
        auto index = key[indexString]-'a';
        auto& e = n.children[index];
        if(e==nullptr)
        {
            e = new TrieNode<T>();
        }
        insert_value(*e, key, ++indexString);
    }
    
    
    T& find_r(TrieNode<T>& n, const string& key, int indexString)
    {
        if(key[indexString]==0) return n.second;
        auto index = key[indexString]-'a';
        auto e = n.children[index];
        if(e==nullptr) throw "Data not found";
        return find_data(*e, key, ++indexString);
    }
    
    void show_r(const TrieNode<T>& n) const 
    {
        if(n.value) cout << n.second << endl;
        for (int i = 0; i < 26; ++i)
        {
            if(n.children[i]!=0)
            {
                show_r(*n.children[i]);
            }
        }
    }
    //const key_value<T>& iterate(const TrieNode<T>& n, string value)
    template <typename PROC>
    void iterate(const TrieNode<T>& n, string value, PROC& p)
    {
        const char* a = "abcdefghijklmnopqrstuvwxyz";
        if(n.value)
        {
            key_value<T> a{value, n.second};
            pair=a;
            p(pair);
        
        }
        for (int i = 0; i < 26; ++i)
        {
            if(n.children[i]!=0) 
            {
                value += a[i];
                iterate(*n.children[i], value,p);

            }
        }  
    }
    template <typename PROC>
    //const key_value<T>& iterate_by_prefix_r(const TrieNode<T>& n, const string& prefix, PROC& p int indexString, string value)
    void iterate_by_prefix_r(const TrieNode<T>& n, const string& prefix, PROC& p, int indexString, string value)
    {   
        const char* a = "abcdefghijklmnopqrstuvwxyz";
        if(prefix[indexString]==0)
        {
            iterate(n, value, p);
            return;
        } 
        auto index = prefix[indexString]-'a';
        auto e = n.children[index];
        value+= a[index];
        iterate_by_prefix_r(*e, prefix, p, ++indexString, value);
    }

    void clear_data(const TrieNode<T>& n)
    {
        for (int i = 0; i < 26; ++i)
        {
            if(n.children[i]!=0) 
            {
                clear_data(*n.children[i]);
                delete n.children[i];
                cout << "Children Node was deleted\n";
            }
        }
    }

public:
    
    T& find_data(const string& key)
    {
        return find_data(root, key, 0);
    }
    void insert(const string& key, const T& value)
    {
        insert(root, key, value, 0);
    }
    
    T& insert_value(const string& key)
    {
        return insert_value(root, key, 0);
    }
    size_t size() const
    {
        return lentrie;
    }
    T& operator[](const string& key) //if does not find it, creates it.
    {
        try
        {
            return find_data(key); 
        }
        catch(const char* s)
        {
            return insert_value(key);
        }
    }
    
    void show() const
    {
        show_r(root);
    }
    using iterator = TrieMapIterator<T>;

    iterator find(const string& key)
    {
        TrieMapIterator<T> h{&root, lentrie, 0, find_r(root, key, 0)};
        return h;
    }
    iterator begin()
    {
        TrieMapIterator<T> h{&root, lentrie, 0};
        h.setpositions();
        return h;
    }
    iterator end()
    {
        TrieMapIterator<T> h{&root, 0, lentrie};
        return h;
    }
    
    template <typename PROC>
    void iterate_by_prefix(const string& prefix, PROC p)
    {
        string key;
        iterate_by_prefix_r(root, prefix, p, 0,  key);
    }
    ~trie()
    {
        clear_data(root);
    }
};

//La idea es que dada una clave (siempre como string, dada la naturaleza del Trie), se pueda almacenar un valor de cualquier tipo T en el nodo específico.



int main()
{
    trie<int> s;
    s.insert("diez", 10);
    s.insert("dieciocho", 18);
    s.insert("diecinueve", 19);
    
    s["veinte"] = 20;
    s["veintiuno"] = 21;
    
    //s.show();


    auto it = s.find("veinte");
    if (it == s.end()) cerr << "Not found\n"; 
    else cout << it->second << "\n";
    cout << "-------------------------\n";

    //should iterate diez, dieciocho and diecinueve
    s.iterate_by_prefix("die", [](auto& p)
                                    {
                                    cout << "Key: " << p.first << "; Value: " << p.second << "\n";
                                    });
    cout << "**************************\n";

    // should get all items as pairs

    for (auto& i : s) { cout << i.second  << "\n"; }

}