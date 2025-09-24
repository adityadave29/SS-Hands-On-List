/*
============================================================================================================================================================
Name : 25.c
Author : Aditya Dave
Description: Write a program to create three child processes. Parent should wait for a particular child using waitpid system call.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t child_pid_1, child_pid_2, child_pid_3;
    child_pid_1 = fork();
    if (child_pid_1 == 0)
    {
        sleep(1);
        printf("1st child process with pid %d execute\n", getpid());
        return 0;
    }
    child_pid_2 = fork();
    if (child_pid_2 == 0)
    {
        sleep(7);
        printf("2nd child process with pid %d executed\n", getpid());
        return 0;
    }
    child_pid_3 = fork();
    if (child_pid_3 == 0)
    {
        sleep(4);
        printf("3rd child process with pid %d executed\n", getpid());
        return 0;
    }
    int pid3_res = waitpid(child_pid_3, NULL, 0);
    printf("Parent process with pid %d executed after 3rd child process: %d\n", getpid(), pid3_res);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que25 % ./25
1st child process with pid 9046 execute
3rd child process with pid 9048 executed
Parent process with pid 9045 executed after 3rd child process: 9048
adityadave@Adityas-MacBook-Air-3 Que25 % 2nd child process with pid 9047 executed
*/