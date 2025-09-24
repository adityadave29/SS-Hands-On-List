/*
============================================================================================================================================================
Name : 20.c
Author : Aditya Dave
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    int current_process_id = getpid();
    int priority = getpriority(PRIO_PROCESS, current_process_id);
    printf("Priority of Current process with pid : %d is %d\n", current_process_id, priority);
    setpriority(PRIO_PROCESS, current_process_id, priority + 5);
    printf("New Priority of Current process with pid : %d is %d\n", current_process_id, getpriority(PRIO_PROCESS, current_process_id));
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que20 % ./20
Priority of Current process with pid : 7135 is 0
adityadave@Adityas-MacBook-Air-3 Que20 % sudo nice -n 5 ./20
Priority of Current process with pid : 7135 is 5
adityadave@Adityas-MacBook-Air-3 Que20 % ./20
Priority of Current process with pid : 5465 is 0
New Priority of Current process with pid : 5465 is 5
*/