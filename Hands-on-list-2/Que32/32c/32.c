#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>

#define SEM_NAME "/printer_sem"

int main()
{
    sem_t *sem;

    // Counting semaphore initialized to 2 (since we have 2 printers)
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 2);

    printf("Process %d: waiting for a printer...\n", getpid());
    sem_wait(sem);

    printf("Process %d: got a printer! Printing...\n", getpid());
    sleep(10);

    printf("Process %d: done printing, releasing printer.\n", getpid());
    sem_post(sem);

    sem_close(sem);
    return 0;
}

/*

Terminal 1:
adityadave@Adityas-MacBook-Air-3 32c % ./32c
Process 5512: waiting for a printer...
Process 5512: got a printer! Printing...
Process 5512: done printing, releasing printer.

Terminal 2:
adityadave@Adityas-MacBook-Air-3 32c % ./32c
Process 5502: waiting for a printer...
Process 5502: got a printer! Printing...
Process 5502: done printing, releasing printer.

Terminal 3:
adityadave@Adityas-MacBook-Air-3 32c % ./32c
Process 5518: waiting for a printer...
*/