#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    printf("Process started. PID = %d\n", getpid());
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored. Try pressing Ctrl+C (nothing will happen).\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT reset to default. Try pressing Ctrl+C again (process will terminate).\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que9 % ./a.out
Process started. PID = 7703
SIGINT is now ignored. Try pressing Ctrl+C (nothing will happen).
^C^CSIGINT reset to default. Try pressing Ctrl+C again (process will terminate).
^C
*/