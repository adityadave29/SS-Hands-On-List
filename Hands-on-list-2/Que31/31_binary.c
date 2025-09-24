#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#ifndef __APPLE__
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

int main()
{
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    union semun arg;
    arg.val = 1;

    semctl(semid, 0, SETVAL, arg);

    printf("Binary semaphore (MUTEX/LOCK) created: semid=%d, initial value=%d\n", semid, arg.val);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que31 % ./31b
Binary semaphore (MUTEX/LOCK) created: semid=65536, initial value=1
*/