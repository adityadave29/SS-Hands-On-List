/*
============================================================================================================================================================
Name : 25a.c
Author : Aditya Dave
Description: Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
int main()
{
    key_t key;
    int msqid;
    struct msqid_ds buf;

    key = ftok("msgfile", 65);
    msqid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msqid, IPC_STAT, &buf);
    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);

    printf("Last msg sent time: %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet\n");
    printf("Last msg received time: %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet\n");
    printf("Last change time: %s", ctime(&buf.msg_ctime));

    printf("Current number of bytes in queue: %lu\n", buf.msg_cbytes);
    printf("Number of messages in queue: %lu\n", buf.msg_qnum);
    printf("Max bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que25 % ./a.out
Access Permissions: 666
UID: 501
GID: 20
Last msg sent time: Not yet
Last msg received time: Not yet
Last change time: Mon Sep 22 10:51:46 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Max bytes allowed: 2048
PID of last msgsnd: 0
PID of last msgrcv: 0
*/