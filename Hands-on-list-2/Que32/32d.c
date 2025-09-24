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
    key_t key = ftok("ticketfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, IPC_RMID);
    printf("Semaphore removed.\n");
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que32 % ./a.out
Semaphore removed.
*/