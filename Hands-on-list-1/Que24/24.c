/*
============================================================================================================================================================
Name : 24.c
Author : Aditya Dave
Description: Write a program to create an orphan process.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        sleep(10);
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        exit(0);
    }

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que24 % ./24
Parent process: PID = 8868, Child PID = 8869
Child process: PID = 8869, Parent PID = 1a
*/