/*
============================================================================================================================================================
Name : 30.c
Author : Aditya Dave
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 15th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include <syslog.h>

#define LOGGING "Start Logging my task = %d\n"

int main()
{

    // I followed seven step to create daemon process.
    pid_t pid;
    int x_fd;

    // STEP 1
    pid = fork();
    if (pid > 0)
        exit(EXIT_SUCCESS);

    // STEP 2
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    // STEP 3
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    // STEP 4
    pid = fork();
    if (pid > 0)
    {
        printf("Daemon PID: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    // STEP 5
    umask(077);

    // STEP 6
    chdir("/");

    // STEP 7
    for (x_fd = sysconf(_SC_OPEN_MAX); x_fd >= 0; x_fd--)
        close(x_fd);

    // STEP 8
    int count = 0;
    openlog("Logs", LOG_PID, LOG_USER);
    while (1)
    {
        sleep(2);
        syslog(LOG_INFO, LOGGING, count++);
    }
    closelog();
    return 0;
}

// ps -ef | grep mydaemon
// log show --predicate 'process == "Logs"' --last 2m
// kill -9 <PID>

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que30 % ./daemon
Daemon PID: 23056
adityadave@Adityas-MacBook-Air-3 Que30 % ps -ef | grep daemon

    0   324     1   0 Fri11AM ??         0:06.64 /usr/sbin/systemstats --daemon
    0   330     1   0 Fri11AM ??         0:00.03 /usr/libexec/IOMFB_bics_daemon
  241   369     1   0 Fri11AM ??         0:14.70 /usr/sbin/distnoted daemon
   88   386     1   0 Fri11AM ??       113:46.26 /System/Library/PrivateFrameworks/SkyLight.framework/Resources/WindowServer -daemon
    0   388     1   0 Fri11AM ??         0:39.40 /usr/sbin/cfprefsd daemon
    0 23053     1   0 10:44AM ??         0:00.03 /System/Library/CoreServices/ReportCrash daemon
  501 23056     1   0 10:44AM ??         0:00.01 ./daemon
  501 23073 21521   0 10:45AM ttys003    0:00.00 grep daemon
*/