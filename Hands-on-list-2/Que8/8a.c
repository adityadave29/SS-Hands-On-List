#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segv_handler(int signum)
{
    printf("Caught SIGSEGV: Invalid memory access!: %d\n", signum);
    exit(1);
}

int main()
{
    signal(SIGSEGV, segv_handler);
    int *p = NULL;
    *p = 100;
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que8 % ./a.out
Caught SIGSEGV: Invalid memory access!: 11
*/