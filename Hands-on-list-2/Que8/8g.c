/*
============================================================================================================================================================
Name : 8g.c
Author : Aditya Dave
Description: Write a separate program using signal system call to catch SIGPROF (use setitimer system call).
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Caught SIGPROF: Process used enough CPU (user + kernel) time!\n");
}

int main()
{
    signal(SIGPROF, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1)
    {
        for (volatile long i = 0; i < 100000000; i++)
        {
        }
        read(STDIN_FILENO, NULL, 0);
    }
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Caught SIGPROF: Process used enough CPU (user + kernel) time!
Caught SIGPROF: Process used enough CPU (user + kernel) time!
Caught SIGPROF: Process used enough CPU (user + kernel) time!
Caught SIGPROF: Process used enough CPU (user + kernel) time!
*/