/*
============================================================================================================================================================
Name : 10a.c
Author : Aditya Dave
Description: Write a separate program using sigaction system call to catch SIGSEGV.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 42;

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que10 % ./a.out
Caught SIGSEGV (Segmentation Fault)
*/