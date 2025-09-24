#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0)
    {
        dup2(pipe1[1], 1);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }

    if (fork() == 0)
    {
        dup2(pipe1[0], 0);
        dup2(pipe2[1], 1);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);
        exit(1);
    }

    if (fork() == 0)
    {
        dup2(pipe2[0], 0);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("wc", "wc", NULL);
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que18 % ./a.out
       0       0       0
*/