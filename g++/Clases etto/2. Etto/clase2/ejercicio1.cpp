//herencia virtual
#include <cstdio>
struct X
{
	virtual void doSomething()=0;
};
struct Y:public virtual X{
	void doSomething()
	{
		puts ("OOPS");
	}
};
struct Z:public virtual X{};
struct ZZZ:public virtual Y,public virtual Z
{
	void doSomething() override
	{
		puts("Hello From dev 26");
	}

};
int main()
{
	/*ZZZ z;
	z.doSomething();*/
	X* x=new ZZZ();//asi nomas funciona no al reves 
	Y* y=new Y();
	Z* z=new ZZZ();
	ZZZ* z2=new ZZZ();
	x->doSomething();
	y->doSomething();
	z2->doSomething();
	z->doSomething();

}

