#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name)
{
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0)
        printf("%-20s: soft=%ld  hard=%ld\n", name, (long)limit.rlim_cur, (long)limit.rlim_max);
}

int main()
{
    struct rlimit new_limit;

    printf("Before change:\n");
    print_limit(RLIMIT_NOFILE, "Open files");

    new_limit.rlim_cur = 512;
    new_limit.rlim_max = 8781529112;

    setrlimit(RLIMIT_NOFILE, &new_limit);

    printf("\nAfter change:\n");
    print_limit(RLIMIT_NOFILE, "Open files");

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que3 % sudo ./3
Before change:
Open files          : soft=10240  hard=9223372036854775807
After change:
Open files          : soft=512  hard=8781529112
*/