#include <unistd.h>
#include <stdio.h>

int main( int argc, char** argv)
{
	if (argc == 1)
	{
		printf("Error argument");
	}
	execvp( argv[1], &argv[1]);
	printf("Error\n");	
	return 0;
}
