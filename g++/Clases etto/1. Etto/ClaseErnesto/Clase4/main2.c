
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	int* e = (int*)calloc(10000*sizeof(int)); //calloc inicializa todo con cero, recerva el numero de espacios

	//memset(e,0,10000*sizeof(int)) para inicializar con malloc en ceros

	for(int i=0;i<10000;i++)
	{
		cout<<e[i]<<endl;
	}

	free(e);
}