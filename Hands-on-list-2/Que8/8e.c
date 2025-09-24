#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

time_t start_time;

void alarm_handler(int sig)
{
    time_t now = time(NULL);
    printf("Caught SIGALRM (setitimer): Timer expired! Elapsed: %ld seconds\n",
           now - start_time);
}

int main()
{
    start_time = time(NULL);

    signal(SIGALRM, alarm_handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 3;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    while (1)
    {
        pause();
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Caught SIGALRM (setitimer): Timer expired! Elapsed: 2 seconds
Caught SIGALRM (setitimer): Timer expired! Elapsed: 5 seconds
Caught SIGALRM (setitimer): Timer expired! Elapsed: 8 seconds
Caught SIGALRM (setitimer): Timer expired! Elapsed: 11 seconds
Caught SIGALRM (setitimer): Timer expired! Elapsed: 14 seconds
*/