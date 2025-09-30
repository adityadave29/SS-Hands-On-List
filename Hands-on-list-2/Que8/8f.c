/*
============================================================================================================================================================
Name : 8f.c
Author : Aditya Dave
Description: Write a separate program using signal system call to catch SIGVTALRM (use setitimer system call).
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void vtalrm_handler(int sig)
{
    printf("Caught SIGVTALRM: Virtual timer expired!\n");
}

int main()
{
    signal(SIGVTALRM, vtalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1)
    {
        for (volatile int i = 0; i < 1000000; i++)
        {
        }
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Caught SIGVTALRM: Virtual timer expired!
Caught SIGVTALRM: Virtual timer expired!
Caught SIGVTALRM: Virtual timer expired!
Caught SIGVTALRM: Virtual timer expired!
Caught SIGVTALRM: Virtual timer expired!
*/