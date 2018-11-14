// Implement a f_stack<T> (LIFO) class.

// Implement a RPN evaluator class. (1 2 +) will push 1 and 2 in a stack, and the operator + will remove  them and push into them the result of adding them up. It will support the 4 basic operations.

// You can use everything seen at class, but no other stuff.

// Not compiling code will render your exam useless.

// Having memory leaks will subtract 10 points to your last score.

// Do not use inheritance, polymorphism or any virtual thing.

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class f_exception : public exception
{
    const char* text;
public:
    f_exception(const char* text)
    :text{text}
    {
    }
    ~f_exception()
    {
    }
    const char* what() const noexcept override 
    {
        return text;
    }
};

template <typename T>
class Node
{
public:
    T value;
};

template <typename T>
class f_array
{
    size_t size;
    size_t count;
    Node<T> *nodes;
public:
    f_array(const size_t &size) :size{size}, count{0}, nodes{new Node<T>[size]}{}
    ~f_array(){}
    bool is_empty()
    {
        if(count==0)
            return true;
        else
            return false;
    }
    void push(const T &value)
    {
        resize();
        nodes[count++].value = value;
    }
    void resize()
    {
        if(size==count)
        {
            size = size*2;
            Node<T> *aux = new Node<T>[size];
            for (size_t i = 0U; i < count; ++i)
            {
                aux[i] = nodes[i];
            }
            delete[] nodes;
            nodes = aux;
        }
    }
    T pop()
    {
        
        if(count<=0)
        {   
            throw f_exception{"Attempt to pop value from empty stack"};
        }
        else
        {
            T aux_value = nodes[--count].value;
            return aux_value;
        }
        
    }
    template <typename PROC>
    void iterate(PROC p)
    {
        int aux = count;
        for (int i = --aux; i >= 0; --i)
        {
            p(nodes[i].value);
        }
    }
};

template <typename T>
class f_stack
{
    f_array<T> array;
public:
    f_stack(): array{f_array<T>(4)}{}
    ~f_stack(){}
    bool is_empty()
    {
        return array.is_empty();
    }
    void push(const T &value)
    {
        array.push(value);
    }
    T pop()
    {
        return array.pop();
    }
    template <typename PROC>
    void iterate(PROC p)
    {
        array.iterate(p);
    }
};

template <typename PROC>
void split_string(char s,string name, PROC p)
{

    char str[100];
    strcpy(str,name.c_str());
    
    char* pch;
    pch = strtok (str," ");
    while (pch != NULL)
    {
        string value_real = pch;
        // cout<< pch << endl;
        p(value_real);
        pch = strtok (NULL, " ");
    }

}

bool test0()

{
    f_stack<int> st;

    auto r1 = st.is_empty();

    st.push(10);

    auto r2 = st.is_empty();

    return r1 && !r2;
    return 0;
}

bool test1()

{
    f_stack<int> st;

    st.push(50);

    st.push(40);

    st.push(25);

    return st.pop() == 25 && st.pop() == 40; 
    return 0;
}

bool test2()

{
    f_stack<string> s;

    s.push("easy");
    s.push("was");
    s.push("exam");
    s.push("second");

    auto s4 = s.pop();
    auto s3 = s.pop();
    auto s2 = s.pop();
    auto s1 = s.pop();

    return s4 == "second" && s3 == "exam" && s2 == "was" && s1 == "easy" && s.is_empty(); 
    return 0;
}

bool test3()

{

    f_stack<string> sd;

    sd.push("devices");
    sd.push("own");
    sd.push("my");
    sd.push("to");
    sd.push("left");

    string accum;

    sd.iterate([&accum](auto& x)
    {
        accum += x + " ";
    });

    string accum2;

    sd.iterate([&accum2](auto& x)
    {
        accum2 += x + " ";
    });


    return accum == accum2 && accum == "left to my own devices ";
    return 0;
}

bool test4()
{
    try
    {
    cout << "entra" << endl;

        f_stack<string> x;

        x.push("hello");
        x.push("world");

        x.pop();
        x.pop();
        x.pop();

        return false;
    }

    catch (const std::exception& ex)
    {
        return "Attempt to pop value from empty stack"s == ex.what();
    }
}



bool test5()
{

    string result;

    split_string(' ', "abc def ghi jkl", [&result](auto& s)

    {
        result += s + "; ";
    });

    return result == "abc; def; ghi; jkl; ";
    return 0;
}



// bool test6()

// {

//     evaluator m;

//     return m.evaluate("10 30 +") == 40;

// }



// bool test7()

// {

//     evaluator x;

//     return x.evaluate("10 20 50 + *") == 700; }



// bool test8()

// {

//     try

//     {

//         evaluator x;

//         x.evaluate("10 20 + +");

//         return false;

//     }

//     catch (const exception& x)

//     {

//         return "Operand not found"s == x.what();

//     }

// }



// bool test9()

// {

//     evaluator x;

//     x.add_operator("min", [](auto& x, auto& y)

//     {

//         return x < y ? x : y;

//     });



//     return x.evaluate("5 3 * 10 20 - min") == 15; }



using test = bool(*)();



auto main() -> int

{

    test tests[] = { test0,

                     test1,

                     test2,

                     test3,

                     test4,

                     test5,

                     // test6,

                     // test7,

                     // test8,

                     // test9

    };



    size_t score = 0;

    for (auto& t : tests)

    {

        score += t() * 10;

    }



    cout << "Score: " << score << " / 100\n";

    getchar();

    return 0;

}