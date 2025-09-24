/*
============================================================================================================================================================
Name : 19.c
Author : Aditya Dave
Description: Write a program to find out time taken to execute getpid system call using time stamp counter.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc(void)
{
    unsigned int lo, hi;
    __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(int argc, char *argv[])
{
    uint64_t start, end;
    start = rdtsc();
    getpid();
    end = rdtsc();
    double time_taken = (end - start);
    printf("Time taken by getpid() system call is: %1f nano seconds\n", time_taken);
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que19 % ./19
Time taken by getpid() system call is: 9.000000 nano seconds
*/