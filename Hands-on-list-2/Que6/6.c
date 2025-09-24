#include <stdio.h>
#include <pthread.h>
int a = 3, b = 7;

void *func1(void *arg)
{
    printf("Sum of %d and %d is %d\n", a, b, a + b);
    return NULL;
}

void *func2(void *arg)
{
    printf("Difference of %d and %d is %d\n", a, b, a - b);
    return NULL;
}

void *func3(void *arg)
{
    printf("Product of %d and %d is %d\n", a, b, a * b);
    return NULL;
}

int main()
{
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, func1, NULL);
    pthread_create(&th2, NULL, func2, NULL);
    pthread_create(&th3, NULL, func3, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que6 % ./6
Difference of 3 and 7 is -4
Sum of 3 and 7 is 10
Product of 3 and 7 is 21s
*/