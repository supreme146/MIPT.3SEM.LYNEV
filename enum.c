#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		errno = E2BIG;
		pritnf("%s", errno);
		exit(EXIT_FAILURE);
	}
	long int x;
	int base = 10;
	char* endptr; 
	x = strtol( argv[1], &endptr, base);
	if ( *endptr != '\0') exit(EXIT_FAILURE);
	if (( errno == ERANGE)) printf ("%s", strerror(errno));
	
	exit(EXIT_SUCCESS);	
