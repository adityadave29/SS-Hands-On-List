#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    struct sigaction sa;

    printf("Process started (PID=%d).\n", getpid());
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now ignored. Try pressing Ctrl+C (nothing will happen)...\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT reset to default. Try pressing Ctrl+C again (program will terminate).\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}
/*
adityadave@Adityas-MacBook-Air-3 Que11 % ./a.out
Process started (PID=8420).
SIGINT is now ignored. Try pressing Ctrl+C (nothing will happen)...
^CSIGINT reset to default. Try pressing Ctrl+C again (program will terminate).
^C
*/