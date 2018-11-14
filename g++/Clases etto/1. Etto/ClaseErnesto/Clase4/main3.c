#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	char* b = (char*)malloc(2);

	b[0]= 'h';
	b[1]= '\0';

	cout<<b<<endl;

	b = (char*)realloc(b,6);//recerva un espacio libre 
	strcpy(b+1,"ello");
	cout<<b<<endl;
}