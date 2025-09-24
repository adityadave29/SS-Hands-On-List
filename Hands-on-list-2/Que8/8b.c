#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void int_handler(int sig)
{
    printf("Caught SIGINT (Ctrl+C pressed)\n");
    exit(1);
}

int main()
{
    signal(SIGINT, int_handler);
    while (1)
    {
        printf("Working...\n");
        sleep(1);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Working...
Working...
^CCaught SIGINT (Ctrl+C pressed)
*/