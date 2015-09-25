#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int size;
    int fileid;
    char buf[4096];
    char buf2[4096];
    int pipefd[2];
    pid_t cpid;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
	if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0)
    {
        fileid = open( argv[1], O_RDONLY);
        close(pipefd[0]);
	//size = 0;
	size = read(fileid, &buf2, 4096);
        while ( size > 0)
	{
        write(pipefd[1], &buf2, size);
	size = read(fileid, &buf2, 4096);
	}
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }else
    {
        close(pipefd[1]);
	//size = 0;
	size = read(pipefd[0], &buf, 4096);
        while ( size > 0)
	{
	write(STDOUT_FILENO, &buf, size);
	size = read(pipefd[0], &buf, 4096);
	}
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
return 0;
}
