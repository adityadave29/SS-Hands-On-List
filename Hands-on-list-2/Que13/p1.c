#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{
    printf("Caught signal %d\n", signum);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSTOP, &sa, NULL);
    printf("PID = %d, waiting for SIGSTOP...\n", getpid());
    while (1)
    {
        sleep(1);
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que13 % ./p1
PID = 9078, waiting for SIGSTOP...
zsh: suspended (signal)  ./p1
*/