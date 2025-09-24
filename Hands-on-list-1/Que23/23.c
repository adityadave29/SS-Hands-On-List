/*
============================================================================================================================================================
Name : 23.c
Author : Aditya Dave
Description: Write a program to create a Zombie state of the running program.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child process with PID=%d\n", getpid());
        printf("Child process executed.");
    }
    else
    {
        sleep(10);
        printf("Parent process with PID=%d created child with PID=%d\n", getpid(), pid);
    }

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que23 % ./23
Child process with PID=8619
Child process executed.Parent process with PID=8618 created child with PID=8619

adityadave@Adityas-MacBook-Air-3 Que23 % ps -l -p 8619
  UID   PID  PPID        F CPU PRI NI       SZ    RSS WCHAN     S             ADDR TTY           TIME CMD
  501  8619  8618     2006   0   0  0        0      0 -      Z+                  0 ttys003    0:00.00 <defunct>
*/