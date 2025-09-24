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

    key = ftok("p_file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hi, How are you? I am Aditya.");
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Message sent to queue with ID: %d\n", msgid);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que26 % ./a.out
Message sent to queue with ID: 65538
adityadave@Adityas-MacBook-Air-3 Que26 % ipcs -q
IPC status from <running system> as of Mon Sep 22 10:56:37 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0xffffffff --rw-rw-rw- adityadave    staff
q  65537 0x41120703 --rw-rw-rw- adityadave    staff
q  65538 0x41128fbb --rw-rw-rw- adityadave    staff
*/