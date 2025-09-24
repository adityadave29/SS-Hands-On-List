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