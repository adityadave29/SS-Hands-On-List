#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#if defined(__APPLE__)
#include <sys/sysctl.h>
#endif

int main()
{
    printf("a. Max length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("b. Max number of processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("c. Number of clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("d. Max number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("e. Size of a page (bytes): %ld\n", sysconf(_SC_PAGESIZE));
#if defined(__linux__)
    printf("f. Total number of pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("g. Number of available pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));
#elif defined(__APPLE__)
    int mib[2];
    int64_t physical_memory;
    size_t length = sizeof(physical_memory);
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    sysctl(mib, 2, &physical_memory, &length, NULL, 0);
    printf("f. Total physical memory: %lld bytes (%.2f GB)\n", physical_memory, physical_memory / (1024.0 * 1024 * 1024));
#endif

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que5 % ./5
a. Max length of arguments to exec: 1048576
b. Max number of processes per user ID: 1333
c. Number of clock ticks per second: 100
d. Max number of open files: 10240
e. Size of a page (bytes): 16384
f. Total physical memory: 8589934592 bytes (8.00 GB)
*/