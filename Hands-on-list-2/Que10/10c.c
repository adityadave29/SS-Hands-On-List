#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    printf("Caught SIGFPE (Divide by zero)\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    int x = 1 / 0;
    printf("x = %d\n", x);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que10 % gcc 10c.c
10c.c:20:15: warning: division by zero is undefined [-Wdivision-by-zero]
   20 |     int x = 1 / 0;
      |               ^ ~
1 warning generated.
*/