#include<iostream>
using namespace std;
class Object
{
public:
	virtual bool equals (const Object&)const=0;
	virtual ~Object (){}
};

class IComparable:public virtual Object//se llaman abcs Abstract Base class
{
public:
		
	virtual ~IComparable() { }
	virtual int compareTo(const Object& src)const =0;
};

class Integer:public virtual Object,public virtual IComparable
{
	int n;
public:
	Integer(int n):n{n}{}
	bool equals (const Object& src)const override
	{
		auto s=dynamic_cast<const Integer&>(src);
		return n==s.n;
	}
	int compareTo(const Object& src)const override
	{
		auto s=dynamic_cast<const Integer&>(src);
		return n-s.n;
	}

};


		

int main()
{
	IComparable* s=new Integer(2);
	Object* p=new Integer(4);
	cout<<s->equals(*p)<<"\n";
	cout<<s->compareTo(*p)<<"\n";
}