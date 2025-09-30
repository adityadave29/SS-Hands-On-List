/*
============================================================================================================================================================
Name : 24.c
Author : Aditya Dave
Description: Write a program to create a message queue and print the key and message queue id.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main()
{
    key_t key;
    int msgid;

    key = ftok("key_progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que24 % ./24
Message Queue Key: 1091522980
Message Queue ID: 65536
*/