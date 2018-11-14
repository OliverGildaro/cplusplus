#include <iostream>

using namespace std;

class P
{
	int x;

	public:
		P(int x):x{x}
		{
		}
		virtual ~P(){} //si usamos el metodo VIRTUAL hay que crear un desctructor virtual

		virtual void show() const // llama a VTABLE y cusca el metodo show de la clase hija
		{
			cout<<x<<endl;
		}
	protected:
		size_t get_x() const
		{
			return x;
		}

};

class Q: public P
{
	int y;

	public:
		Q(int x, int y):P{x},y{y}
		{

		}

	~Q(){} 

	void show2() const
	{
		P::show();
		cout<<y<<endl;
	}

	void show() const override//HIDING ES COMO POLIMORFISMO en compilacion
	{
		cout<<get_x()<<";"<<y<<endl;
	}
};

int main()
{
	P p{16};

	p.show();

	Q q{8,14};
	q.show();
	q.show2();

	P* pp = new P{25};
	pp->show();

	Q* pq = new Q{100,105};
	pq->show();

	P* qq = new Q{36,66};
	qq->show();

	delete pp;
	delete pq;
	delete qq;

}	