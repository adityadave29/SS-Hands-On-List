#include <stdio.h>
#include <pthread.h>

void *func(void *arg)
{
    printf("Thread started with id: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main()
{
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, func, NULL);
    pthread_create(&th2, NULL, func, NULL);
    pthread_create(&th3, NULL, func, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    printf("Main thread ID: %lu\n", (unsigned long)pthread_self());
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que7 % ./7
Thread started with id: 6169882624
Thread started with id: 6170456064
Thread started with id: 6171029504
Main thread ID: 8784142528
*/