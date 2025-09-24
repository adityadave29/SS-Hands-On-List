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

    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

    static int ticket = 0;

    for (int i = 0; i < 5; i++)
    {
        sem_wait(semid);
        ticket++;
        printf("Process %d got ticket number %d\n", getpid(), ticket);
        sem_signal(semid);
        sleep(1);
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que32 % ./a.out
Process 4762 got ticket number 1
Process 4762 got ticket number 2
Process 4762 got ticket number 3
Process 4762 got ticket number 4
Process 4762 got ticket number 5
*/