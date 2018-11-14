#include <iostream>
#include <string>
#include <stdlib.h> //para incluir malloc
#include <stdio.h> // de cuenta del iostream
using namespace std;

int main()
{
	void* p = malloc(size_of(int));

	int* q =(int*)p;

	int* q = 8;
	cout<<*q<<endl;
	char* r = (char*)p;
	strcpy(r,"bye");
	cout<<r<<endl;
	free(r);
}
