/*
============================================================================================================================================================
Name : 8d.c
Author : Aditya Dave
Description: Write a separate program using signal system call to catch SIGALRM (use alarm system call).
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int sig)
{
    printf("Caught SIGALRM: Timer expired!\n");
}

int main()
{
    signal(SIGALRM, alarm_handler);
    alarm(3);
    while (1)
    {
        printf("Waiting...\n");
        sleep(1);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Waiting...
Waiting...
Waiting...
Caught SIGALRM: Timer expired!
Waiting...
Waiting...
*/