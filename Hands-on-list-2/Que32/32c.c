#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __APPLE__
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif
void sem_wait(int semid)
{
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void sem_signal(int semid)
{
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

int main()
{
    key_t key = ftok("resfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun u;
    u.val = 2;
    semctl(semid, 0, SETVAL, u);

    printf("Process %d waiting for printer...\n", getpid());
    sem_wait(semid);
    printf("Process %d is using a printer...\n", getpid());
    sleep(3);
    printf("Process %d released printer\n", getpid());
    sem_signal(semid);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que32 % ./a.out
Process 5014 waiting for printer...
Process 5014 is using a printer...
Process 5014 released printer
*/