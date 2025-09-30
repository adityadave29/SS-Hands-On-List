/*
============================================================================================================================================================
Name : 34b.c
Author : Aditya Dave
Description: Write a program to create a concurrent server using pthread_create.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg)
{
    int client_sock = *((int *)arg);
    free(arg);
    printf("Thread %ld: started for client socket %d\n", pthread_self(), client_sock);

    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_sock, buffer, BUFFER_SIZE - 1)) > 0)
    {
        buffer[n] = '\0';
        printf("Thread %ld: received '%s'\n", pthread_self(), buffer);
        write(client_sock, buffer, n);
    }

    printf("Thread %ld: client disconnected, closing socket %d\n", pthread_self(), client_sock);
    close(client_sock);
    return NULL;
}

int main()
{
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    printf("Server listening on port %d...\n", PORT);

    while (1)
    {
        int client_sock = accept(server_sock, NULL, NULL);
        printf("Main thread: client connected, socket=%d\n", client_sock);

        int *pclient = malloc(sizeof(int));
        *pclient = client_sock;

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, pclient);
        pthread_detach(tid);
    }

    close(server_sock);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que34 % ./34b
Server listening on port 8080...
Main thread: client connected, socket=4
Thread 6160314368: started for client socket 4
Thread 6160314368: received 'Hello
'
Thread 6160314368: received 'How are you
'
Main thread: client connected, socket=5
Thread 6160887808: started for client socket 5
Thread 6160887808: received 'Hello
'
*/