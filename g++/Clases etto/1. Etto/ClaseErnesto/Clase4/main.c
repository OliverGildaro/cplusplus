
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	char* r = malloc(15); 

	strcpy(r,"hello world");
	puts(r);
	free (r);

	return 0;
}