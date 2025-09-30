/*
============================================================================================================================================================
Name : 14.c
Author : Aditya Dave
Description: Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
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
    char write_msg[] = "This message is comming from PIPE";
    char read_msg[100];

    pipe(fd);
    write(fd[1], write_msg, strlen(write_msg));
    int n = read(fd[0], read_msg, sizeof(read_msg) - 1);
    read_msg[n] = '\0';
    printf("Message ==> %s\n", read_msg);
    close(fd);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que14 % ./14
Message ==> This message is comming from PIPE
*/