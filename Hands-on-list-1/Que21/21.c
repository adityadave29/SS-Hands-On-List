/*
============================================================================================================================================================
Name : 21.c
Author : Aditya Dave
Description: Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t q;
    q = fork();
    if (q == 0)
        printf("Child process with PID = %d has Parent process with PID = %d\n", getpid(), getppid());
    else
        printf("Parent process with PID = %d has Child process with PID = %d\n", getpid(), q);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que21 % ./21
Parent process with PID = 7231 has Child process with PID = 7232
Child process with PID = 7232 has Parent process with PID = 7231
*/