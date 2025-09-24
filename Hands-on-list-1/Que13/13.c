/*
============================================================================================================================================================
Name : 13.c
Author : Aditya Dave
Description: Write a program to wait for STDIN for 10 seconds using select. Print message whether input was given or timeout occurred.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <sys/select.h>

int main()
{
    fd_set fd;
    struct timeval Ten_sec_timeout = {10, 0};

    FD_ZERO(&fd);
    FD_SET(0, &fd);

    if (select(1, &fd, NULL, NULL, &Ten_sec_timeout))
        printf("User entered data within 10 seconds.\n");
    else
        printf("No data was entered on the terminal within 10 seconds.\n");
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que13 % ./13
Hi
User entered data within 10 seconds.
Hi
*/