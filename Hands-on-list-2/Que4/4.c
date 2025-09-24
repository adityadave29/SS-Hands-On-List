#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc()
{
    unsigned long long cntvct;
    asm volatile("mrs %0, cntvct_el0" : "=r"(cntvct));
    return cntvct;
}

int main()
{
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++)
        getppid();

    end = rdtsc();

    printf("Total CPU cycles for 100 getppid() calls: %llu\n", end - start);
    printf("Average CPU cycles per call: %llu\n", (end - start) / 100);

    return 0;
}

/*
Total CPU cycles for 100 getppid() calls: 1479
Average CPU cycles per call: 14
adityadave@Adityas-MacBook-Air-3 Que4 % ./a.out
Total CPU cycles for 100 getppid() calls: 1485
Average CPU cycles per call: 14
adityadave@Adityas-MacBook-Air-3 Que4 % ./a.out
Total CPU cycles for 100 getppid() calls: 1453
Average CPU cycles per call: 14
*/