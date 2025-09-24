#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);
    if (strcmp(argv[1], "dup") == 0)
    {
        if (fork() == 0)
        {
            close(fd[0]);
            close(1);
            dup(fd[1]);
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        }
        else if (fork() == 0)
        {
            close(fd[1]);
            close(0);
            dup(fd[0]);
            close(fd[0]);
            execlp("wc", "wc", NULL);
            exit(1);
        }
        else
        {
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    else if (strcmp(argv[1], "dup2") == 0)
    {
        if (fork() == 0)
        {
            close(fd[0]);
            dup2(fd[1], 1);
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        }
        else if (fork() == 0)
        {
            close(fd[1]);
            dup2(fd[0], 0);
            close(fd[0]);
            execlp("wc", "wc", NULL);
            exit(1);
        }
        else
        {
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    else if (strcmp(argv[1], "fcntl") == 0)
    {
        if (fork() == 0)
        {
            close(fd[0]);
            close(1);
            fcntl(fd[1], F_DUPFD, 1);
            close(fd[1]);
            execlp("ls", "ls", "-l", NULL);
            exit(1);
        }
        else if (fork() == 0)
        {
            close(fd[1]);
            close(0);
            fcntl(fd[0], F_DUPFD, 0);
            close(fd[0]);

            execlp("wc", "wc", NULL);
            exit(1);
        }
        else
        {
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    else
    {
        printf("Usage: %s <dup|dup2|fcntl>\n", argv[0]);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que17 % ./a.out dup
       3      20     124
adityadave@Adityas-MacBook-Air-3 Que17 % ./a.out dup2
       3      20     124
adityadave@Adityas-MacBook-Air-3 Que17 % ./a.out fcntl
       3      20     124
*/