#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

void print_limit(int resource, const char *name)
{
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0)
    {
        printf("%-20s: soft=%ld  hard=%ld\n", name, (long)limit.rlim_cur, (long)limit.rlim_max);
    }
}

int main()
{
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "File size (bytes)");
    print_limit(RLIMIT_DATA, "Data seg size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NPROC, "Number of processes");
    print_limit(RLIMIT_NOFILE, "Open files");
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que2 % ./2
CPU time (seconds)  : soft=9223372036854775807  hard=9223372036854775807
File size (bytes)   : soft=9223372036854775807  hard=9223372036854775807
Data seg size       : soft=9223372036854775807  hard=9223372036854775807
Stack size          : soft=8372224  hard=67092480
Core file size      : soft=0  hard=9223372036854775807
Resident set size   : soft=9223372036854775807  hard=9223372036854775807
Number of processes : soft=1333  hard=2000
Open files          : soft=10240  hard=9223372036854775807
*/