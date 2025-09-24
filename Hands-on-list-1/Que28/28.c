/*
============================================================================================================================================================
Name : 28.c
Author : Aditya Dave
Description: Write a program to get maximum and minimum real time priority.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <sched.h>

int main()
{
    int min_prio_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_prio_fifo = sched_get_priority_max(SCHED_FIFO);

    int min_prio_rr = sched_get_priority_min(SCHED_RR);
    int max_prio_rr = sched_get_priority_max(SCHED_RR);

    printf("FIFO POLICY => Min Priority = %d, Max Priority = %d\n", min_prio_fifo, max_prio_fifo);
    printf("ROUND ROBIN POLICY => Min Priority = %d, Max Priority = %d\n", min_prio_rr, max_prio_rr);

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que28 % ./28
SCHED_FIFO: Min Priority = 15, Max Priority = 47
SCHED_RR:   Min Priority = 15, Max Priority = 47
*/
