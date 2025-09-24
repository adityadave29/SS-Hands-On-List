#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum)
{
    printf("Caught SIGINT (Ctrl+C pressed)\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Running... Press Ctrl+C\n");
    while (1)
    {
        sleep(1);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que10 % ./a.out
Running... Press Ctrl+C
^CCaught SIGINT (Ctrl+C pressed)
*/