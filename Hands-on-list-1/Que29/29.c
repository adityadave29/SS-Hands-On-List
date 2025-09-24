/*
============================================================================================================================================================
Name : 29.c
Author : Aditya Dave
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);
    if (policy == SCHED_OTHER)
        printf("Current Scheduling Policy: SCHED_OTHER (normal)\n");
    else if (policy == SCHED_FIFO)
        printf("Current Scheduling Policy: SCHED_FIFO (real-time FIFO)\n");
    else if (policy == SCHED_RR)
        printf("Current Scheduling Policy: SCHED_RR (real-time Round Robin)\n");

    if (strcmp(argv[1], "fifo") == 0)
    {
        param.sched_priority = 10;
        if (sched_setscheduler(0, SCHED_FIFO, &param) == 0)
            printf("Changed policy to SCHED_FIFO with priority %d\n", param.sched_priority);
    }
    else if (strcmp(argv[1], "rr") == 0)
    {
        param.sched_priority = 20;
        if (sched_setscheduler(0, SCHED_RR, &param) == 0)
            printf("Changed policy to SCHED_RR with priority %d\n", param.sched_priority);
    }
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que29 % gcc 29.c -o 29
adityadave@Adityas-MacBook-Air-3 Que29 % ./29
 ret = -1
The scheduling policy is = 0
 ret = -1
The scheduling policy is = 0

adityadave@Adityas-MacBook-Air-3 Que29 % sudo ./29
 ret = 0
The scheduling policy is = 1
 ret = 0
The scheduling policy is = 2
In mac we don't have SCHED_FIFO and SCHED_RR support.

*/