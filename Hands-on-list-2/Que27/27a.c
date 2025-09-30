/*
============================================================================================================================================================
Name : 27a.c
Author : Aditya Dave
Description: Write a program to receive messages from the message queue with 0 as a flag.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message.msg_text), 0, 0);
    printf("Received: %s\n", message.msg_text);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que27 % ./a.out
Message sent: Hello from sender!
adityadave@Adityas-MacBook-Air-3 Que27 % ./27a
Received: Hello from sender!
*/