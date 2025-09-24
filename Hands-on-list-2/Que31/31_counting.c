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

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    key_t key = ftok("semfile", 66);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    union semun arg;
    arg.val = N;
    semctl(semid, 0, SETVAL, arg);

    printf("Counting semaphore created with: semid=%d, resources value=%d\n", semid, arg.val);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que31 % ./31c 10
Counting semaphore created with: semid=65536, resources value=10
*/