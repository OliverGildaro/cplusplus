#include <iostream>
#include <cstring>
using namespace std;

constexpr size_t MAXSTR = 16;


class Str
{
    char* s;
    char sso[MAXSTR];
    size_t len;
    
    public:
        Str(const char* s = "")
        :len(strlen(s))
        {
            if (len < MAXSTR)
            {
                memcpy(sso, s, len+1);
            }
            else
            {
                this -> s = new char[len + 1];
                memcpy(this -> s, s, len + 1);
            }
        }
        
    ~Str() //siempre publico
    {
        if(len >= MAXSTR)
        delete[] s;
    }


    const char* data() const
    {
        return len<MAXSTR ? sso:s; //si es verdad ejecuta sso si es falso s
    }

    Str(const Str& src)
    :len {src.len}
    {
        if (len < MAXSTR)
        {
            memcpy(sso, src.sso, len+1);
            return;
        }
        s = new char[len+1];
        memcpy (s, src.s, len+1);
    }

    Str& operator = (const Str& src)
    {
        if (this == &src)
            return *this;
        this -> ~Str();
        len = src.len;
        if (len < MAXSTR)
            memcpy(sso, src.sso, len+1);
        else
        {
            s = new char[len+1];
        }
        return *this;
    }
    
    
    void show() const
    {
        cout << data() << endl;
    }
    
    
    bool operator == (const Str& src) const
    {
        if(this == &src) return true;
        if(len != src.len) return false;
        return memcmp(data(), src.data(), len) == 0;
    }

    bool operator == (const char* s)const
    {
        return strcmp(data(), s) == 0;  // la funcion strcmp compara caracter por caracter  
    }


    Str operator + (const Str& src) const
    {
        auto nlen = len + src.len;
        Str aux;
        if (nlen < MAXSTR)
        {
            memcpy(aux.sso, sso, len);
            memcpy(aux.sso + len, src.sso, src.len+1);
        }
        else
        {
            aux.s = new char[nlen+1];
            memcpy(aux.s, data(), len);
            memcpy(aux.s+len, src.data(), src.len+1);
            
        }
        aux.len = nlen;
        return aux;
    }


    Str& operator += (const Str& src)
    {
        auto nlen = len + src.len;
        if(nlen < MAXSTR)
        {
            memcpy(sso + len, src.sso, src.len+1);
        }
        else
        {
            char* p = new char[nlen+1];
            memcpy(p, data(), len);
            memcpy(p + len, src.data(), src.len+1);
            if (len >= MAXSTR) {this -> ~Str();}
            this -> s = p;
        }
        len = nlen;
        return *this;
    }


    Str substr(size_t index, size_t size)const
    {
    
    
    return *this;    
    }
    


};


int main()
{
    //Str x;
    Str y {"hello world"};
    Str z = "Juan Carlos de Josue Rodriguez";
    cout << y.data() << endl;
    Str a = y;
    Str b = z;
    cout << b.data()<<endl;
    
    Str s = "hello world";
    Str w = "hello";
    w = s;
    w.show();
    if(w == "hello world")
    {
        cout << "igual" << endl;
    }
    else
    {
        cout << "diferente" << endl;
    }
    
    
    Str h = "Hello";
    w = "World";
    z = h + " " + w;
    z.show();
    
    Str x{"devint"};
    x += "26";
    (x += "@fundacion-jala.org").show();
    
    x = "Maria Juana";
    x.substr(6, 5).show();
    
    
} 