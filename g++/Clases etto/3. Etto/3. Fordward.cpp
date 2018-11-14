#include <iostream>

using namespace std;

template <typename T>
class array_list
{
private:
    struct al_iterator
    {
        T *item_pos;
        bool operator!=(const al_iterator &src) const
        {
            return item_pos != src.item_pos;
        }
        al_iterator& operator++()
        {
            item_pos++;
            return *this;
        }
        al_iterator operator++(int)
        {
            al_iterator n {item_pos};
            item_pos++;
            return n;
        }
        T& operator*()
        {
            return *item_pos;
        }
        const T& operator*() const
        {
            return *item_pos;
        }
    };
    T* items;
    size_t cap;
    size_t count;
public:
    // Por lo general se hace este using por standard
    using iterator = al_iterator;
    using type = T;
    array_list(size_t cap = 4)
    :items{new T[cap]},cap{cap},count{0}
    {

    }
    ~array_list()
    {}
    template <typename U>
    void push_back(U&& item)
    {
        resize();
        items[count++] = forward<U>(item);
    }
    template <typename ...ARGS>
    void emplace_back(ARGS&& ...args)
    {
        resize();
        items[count++] = T{forward<ARGS>(args)...};
        //Se llama parameter pack expansion
    }
    iterator begin()
    {
        return iterator{items};
    }
    iterator end()
    {
        return iterator{items+count};
    }
    void resize()
    {
        if (cap != count) return;
        size_t ncap = cap *2;
        T *aux = new T[ncap];
        for (size_t i = 0U; i < count; ++i)
        {
            aux[i] = move(items[i]);
        }
        delete []items;
        items = aux;
        cap = ncap;
    }
    T& operator[](size_t index)
    {
        return items[index];
    }
    const T& operator[](size_t index) const
    {
        return items[index];
    }
};

struct Point
{
    int x,y;
};

template<typename T>
void info(const T& x)
{
    typename T::type aux{};
    cout << aux << "\n";
}

int main(int argc, char const *argv[])
{
    /*array_list<string> s;
    s.push_back("hola");
    s.push_back("mundo");
    s.push_back("hello");
    s.push_back("diez");

    string p = "agosto";
    s.push_back(p);
    s.emplace_back("septiembre");

    for(auto& i:s)
    {
        cout << i << "\n";
    }*/
    /*for (auto i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << "\n";
    }*/
    /*array_list<Point> pts;
    pts.push_back(Point{6,8});
    pts.push_back(Point{12,24});
    pts.push_back(Point{1001,4});

    pts.emplace_back(125,180);
    for(auto& i:pts)
    {
        cout << i.x<<"; "<<i.y << "\n";
    }
    cout<< pts[2].x<<"; "<<pts[2].y<<"\n";*/
    array_list<int> q;
    info(q);
    return 0;
}