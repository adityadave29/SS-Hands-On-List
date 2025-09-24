#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum)
{
    printf("ITIMER_VIRTUAL: Timer expired!\n");
}

int main()
{
    struct itimerval timer;

    signal(SIGVTALRM, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while (1)
        ;
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que1 % ./1
ITIMER_VIRTUAL: Timer expired!
ITIMER_VIRTUAL: Timer expired!
*/
