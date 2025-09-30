/*
============================================================================================================================================================
Name : 32a.c
Author : Aditya Dave
Description: Rewrite the ticket number creation program using semaphore.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>

#define SEM_NAME "/ticket_mutex"
#define DB_FILE "database"

int main()
{
    sem_t *mutex;
    int fd;

    struct
    {
        int ticket_no;
    } database;

    mutex = sem_open(SEM_NAME, O_CREAT, 0644, 1);

    printf("Process %d: waiting to enter critical section...\n", getpid());
    sem_wait(mutex);

    printf("Process %d: inside critical section (holding lock)\n", getpid());
    fd = open(DB_FILE, O_RDWR);
    read(fd, &database, sizeof(database));
    printf("Process %d: Current ticket number = %d\n", getpid(), database.ticket_no);

    sleep(10);
    database.ticket_no++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &database, sizeof(database));
    fsync(fd);

    printf("Process %d: New ticket number written = %d\n", getpid(), database.ticket_no);

    close(fd);

    printf("Process %d: leaving critical section...\n", getpid());
    sem_post(mutex);

    sem_close(mutex);
    return 0;
}

/*
Terminal 1:
adityadave@Adityas-MacBook-Air-3 32a % gcc 32a.c -o 32a -pthread
adityadave@Adityas-MacBook-Air-3 32a % ./32a
Process 4185: waiting to enter critical section...
Process 4185: inside critical section (holding lock)
Process 4185: Current ticket number = 1
Process 4185: New ticket number written = 2
Process 4185: leaving critical section...

Terminal 3:
adityadave@Adityas-MacBook-Air-3 32a % ./32a
Process 4204: waiting to enter critical section...
Process 4204: inside critical section (holding lock)
Process 4204: Current ticket number = 3
Process 4204: New ticket number written = 4
Process 4204: leaving critical section...
*/