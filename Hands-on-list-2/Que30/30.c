#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char *)shmat(shmid, (void *)0, 0);
    strcpy(str, "Hello Shared Memory");

    printf("Data written: %s\n", str);
    shmdt(str);
    str = (char *)shmat(shmid, (void *)0, SHM_RDONLY);

    printf("Data read (read-only): %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que30 % ./30
Data written: Hello Shared Memory
Data read (read-only): Hello Shared Memory
adityadave@Adityas-MacBook-Air-3 Que30 % ipcs -m
IPC status from <running system> as of Wed Sep 17 14:54:42 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Shared Memory:
*/