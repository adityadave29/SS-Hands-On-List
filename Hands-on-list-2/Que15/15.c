/*
============================================================================================================================================================
Name : 15.c
Author : Aditya Dave
Description: Write a simple program to send some data from parent to the child process.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    char read_msg[100];
    pipe(fd);
    if (!fork())
    {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child Process received message from parent ==>: %s\n", read_msg);
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        char buff[] = "Hello from Parent!";
        write(fd[1], buff, sizeof(buff));
        close(fd[1]);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que15 % ./15
Child Process received message from parent ==>: Hello from Parent!
*/