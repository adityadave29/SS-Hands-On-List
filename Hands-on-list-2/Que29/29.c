#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main()
{
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue removed successfully.\n");

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que29 % ./a.out
Message sent: Hello from sender!
adityadave@Adityas-MacBook-Air-3 Que29 % ipcs -q
IPC status from <running system> as of Wed Sep 17 14:46:12 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x410f51a4 --rw-rw-rw- adityadave    staff
q  65537 0xffffffff --rw-rw-rw- adityadave    staff
q  65538 0x410f8fbb --rw-rw-rw- adityadave    staff
q  65539 0x410f9300 --rw-rw-rw- adityadave    staff
q  65540 0x410f9764 --rw-rw-rw- adityadave    staff
q 196613 0x410f995c --rw-rw-rw- adityadave    staff

adityadave@Adityas-MacBook-Air-3 Que29 % ./29
Message queue removed successfully.
adityadave@Adityas-MacBook-Air-3 Que29 % ipcs -q
IPC status from <running system> as of Wed Sep 17 14:46:21 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x410f51a4 --rw-rw-rw- adityadave    staff
q  65537 0xffffffff --rw-rw-rw- adityadave    staff
q  65538 0x410f8fbb --rw-rw-rw- adityadave    staff
q  65539 0x410f9300 --rw-rw-rw- adityadave    staff
q  65540 0x410f9764 --rw-rw-rw- adityadave    staff
*/