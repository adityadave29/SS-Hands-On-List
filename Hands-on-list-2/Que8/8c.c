#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fpe_handler(int sig)
{
    printf("Caught SIGFPE: Divide by zero!\n");
    exit(1);
}

int main()
{
    signal(SIGFPE, fpe_handler);

    int x = 1 / 0;
    printf("%d\n", x);
    return 0;
}

/*
In mac at compile time it ignores the divide by zero error.
adityadave@Adityas-MacBook-Air-3 Que8 % gcc 8c.c
8c.c:15:15: warning: division by zero is undefined [-Wdivision-by-zero]
   15 |     int x = 1 / 0;
      |
*/
