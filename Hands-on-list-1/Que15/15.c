/*
============================================================================================================================================================
Name : 15.c
Author : Aditya Dave
Description: Write a program to display the environmental variable of the user (use environ).
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
extern char **environ;
int main()
{
    char **ans = environ;
    printf("Environment variables are:\n");
    while (*ans != NULL)
    {
        printf("%s\n", *ans);
        ans++;
    }
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que15 % ./15
Environment variables:
MallocNanoZone=0
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/opt/llvm/bin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/opt/homebrew/opt/coreutils/libexec/gnubin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/homebrew/bin:/opt/homebrew/lib/python3.13/site-packages/pip:/Users/adityadave/Library/Python/3.9/bin:/Users/adityadave/.local/bin
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.hvEW9nfM4q/Listeners
HOME=/Users/adityadave
SHELL=/bin/zsh
// There are more but I removed.
*/