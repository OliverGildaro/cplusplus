//PAUSA ECOLOGICA
//*malloc/realloc/calloc/free
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int* p =(int*)malloc(5*sizeof(int)); //malloc recerva el numero de bits

	if(p==nullptr)
		exit(-2);
		p[0] = 8;
		p[1] = 45;

		cout<<p[1] +p[0]<<endl;
	free(p);
}


