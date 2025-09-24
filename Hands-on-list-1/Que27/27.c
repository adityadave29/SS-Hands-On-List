/*
============================================================================================================================================================
Name : 27.c
Author : Aditya Dave
Description: Write a program to execute ls -Rl using execl, execlp, execle, execv, and execvp system calls.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "execl") == 0)
    {
        execl("/bin/ls", "ls", "-Rl", NULL);
    }
    else if (strcmp(argv[1], "execlp") == 0)
    {
        execlp("ls", "ls", "-Rl", NULL);
    }
    else if (strcmp(argv[1], "execle") == 0)
    {
        char *envp[] = {"PATH=/bin", NULL};
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
    }
    else if (strcmp(argv[1], "execv") == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
    }
    else if (strcmp(argv[1], "execvp") == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
    }

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que27 % ./27 execl
total 80
-rwxr-xr-x@ 1 adityadave  staff  33760 Sep  1 15:30 27
-rw-r--r--@ 1 adityadave  staff   1204 Sep  3 16:40 27.c
adityadave@Adityas-MacBook-Air-3 Que27 % ./27 execvp
total 80
-rwxr-xr-x@ 1 adityadave  staff  33760 Sep  1 15:30 27
-rw-r--r--@ 1 adityadave  staff   1391 Sep  3 16:45 27.c
*/