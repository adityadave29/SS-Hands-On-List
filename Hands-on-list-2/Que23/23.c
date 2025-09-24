#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main()
{
    struct rlimit rl;
    if (getrlimit(RLIMIT_NOFILE, &rl) == 0)
    {
        printf("Max open files (soft limit): %ld\n", rl.rlim_cur);
        printf("Max open files (hard limit): %ld\n", rl.rlim_max);
    }

    int fd_pipe[2];
    if (pipe(fd_pipe) == 0)
    {
#ifdef F_GETPIPE_SZ // Linux only
        int size = fcntl(pipefd[0], F_GETPIPE_SZ);
        printf("Default pipe size (circular buffer): %d bytes\n", size);
#else
        printf("Default pipe size (circular buffer): 16384 bytes (fixed on macOS)\n");
#endif
        close(fd_pipe[0]);
        close(fd_pipe[1]);
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que23 % ./23
Max open files (soft limit): 10240
Max open files (hard limit): 9223372036854775807
Default pipe size (circular buffer): 16384 bytes (fixed on macOS)
*/