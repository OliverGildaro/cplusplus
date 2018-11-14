#include <iostream> 
using namespace std;
struct ME
{
	int n;
	~ME()
	{
		cout<<"Write exception\n";
	}
};
void m()
{
	cout<<"hola\n";
	//throw new ME{18};//esto no hacer
	throw  ME{18};//esto si
}





int main()
{
	try
	{
		m();
	}
	catch(const ME& ex)//esto es del ME{18};
	{
		cerr<<ex.n<<"\n";
	}
}