
#include <iostream>
#include <cstring>
#include <cstdio>

class student
{
private:
    size_t id;
    char* name;
    size_t len;

public:
    student(const size_t& id, const char* name)
    :id{id}
    { 
        puts("const parameterized");
        len = strlen(name);
        this->name = new char[len+1];
        memcpy(this->name, name, len+1);
    }

    // student(const size_t&, const char*) = delete;
    // student(const student& ) = delete;

    student(const student& src)
    {
        puts("const overload");
        this->~student();
        id = src.id;
        len = src.len;
        name = new char[len+1];
        memcpy(this->name, src.name, len+1);
    }   

    const student& operator=(const student& src)
    {
        puts("Overload operator");
        if(this == &src)
        {
            puts("The same object");
            return *this;
        }
        this->~student();
        id = src.id;
        size_t len = src.len;
        name = new char[len+1];
        memcpy(name, src.name, len+1);
        return *this;
    }

    ~student() 
    { 
        delete[] name;
        puts("bye");
    }

    void show() const
    {
        std::cout << "Id: " << id << "   Name: " << name << std::endl;
    }
};

student subscribe()
{
    return student{456, "Alvaro Castro"};
}


class student_pair
{
private:
    student a;
    student b;

public:
    student_pair(const size_t& id_a, const char* name_a,
        const size_t& id_b, const char* name_b)
        :a{student{id_a, name_a}}, b{student{id_b, name_b}} { }

    ~student_pair() { }

    const student& get_a() const
    {
        return a;
    }
};

int main()
{
    student s1{123,"Carolina Castro"};
    s1.show();
    puts("");

    student s2{s1};
    s2.show();
    puts("");

    student s3 = subscribe();
    s3.show();
    puts("");

    student *s4 = new student(333,"Ivan Castro");
    s4->show();
    delete s4;
    puts("");

    student s5 = s3 = s1;
    s3.show();
    s5.show();
    puts("");

    student_pair s{668,"Juan Perez", 669, "Marta Lopez"};
    s.get_a().show();
    puts("");
}