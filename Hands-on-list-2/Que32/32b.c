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
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

    sem_wait(semid);
    sprintf(str, "Written by process %d", getpid());
    printf("Process %d wrote to shared memory\n", getpid());
    sem_signal(semid);

    shmdt(str);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que32 % ./a.out
Process 4896 wrote to shared memory
*/