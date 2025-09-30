/*
============================================================================================================================================================
Name : 13.c
Author : Aditya Dave
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    pid_t pid = atoi(argv[1]);
    kill(pid, SIGSTOP);
    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que13 % ./p2 9078
Sent SIGSTOP to process 9078
*/