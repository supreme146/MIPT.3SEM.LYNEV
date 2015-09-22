#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
    int size_string = 0;
    char *endptr = 0;
    char *str;
    if (argc != 2)
    {
        errno = E2BIG;
        printf("%s",strerror(errno));
        exit(1);
    }
    int numb_of_fork = strtol(argv[1],&endptr,10);
    if (*endptr != '\0')
        exit(1);
    if ((errno == ERANGE ))
        printf("%s",strerror(errno));

	pid_t pid = 0;
	int i;
	for ( i = 0; i < numb_of_fork; i++)
	{
		pid = fork();
		if( pid == 0)
		{	
			break;
		}
		else if (pid > 0)
		{
			int status = 0;
			wait(&status);
		}
		else
		{
			printf("Error in forking");
		}
	}
	if (pid == 0)
	{
		printf("N: %i, pid: %i, ppid: %i\n", i, getpid(), getppid());
	}
	return 0;
}
