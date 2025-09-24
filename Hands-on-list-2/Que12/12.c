// orphan_process.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    pid_t pid = fork();
    if (!pid)
    {
        printf("Child: My PID = %d, Parent PID = %d\n", getpid(), getppid());

        kill(getppid(), SIGKILL);
        printf("Child: Sent SIGKILL to parent (PID = %d)\n", getppid());
        sleep(2);
        printf("Child: My new Parent PID = %d (should be 1 or systemd)\n", getppid());

        while (1)
        {
            sleep(1);
        }
    }
    else
    {
        printf("Parent: My PID = %d, Child PID = %d\n", getpid(), pid);
        while (1)
        {
            sleep(1);
        }
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que12 % ./a.out
Parent: My PID = 8887, Child PID = 8888
Child: My PID = 8888, Parent PID = 8887
Child: Sent SIGKILL to parent (PID = 8887)
zsh: killed     ./a.out
adityadave@Adityas-MacBook-Air-3 Que12 % Child: My new Parent PID = 1 (should be 1 or systemd)
*/