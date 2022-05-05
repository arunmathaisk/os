#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
void childSigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Child: Recieved signal SIGNUSR1 from parent..\n");
        sleep(1);
    }
    else if (sig == SIGUSR2)
    {
        printf("Child: Recieved signal SIGNUSR2 from parent..\n");
        sleep(5);
    }

    exit(0);
}
int main()
{
    int pid;
    pid = fork();

    if (pid)
    {
        int t;
        srand((unsigned int)time(NULL));
        t = 2 + rand() % 4;
        printf("Parent is going to sleep for %d\n", t);
        sleep(t);
        t = 1 + rand() % 2;
        printf("Parent is going to send SIGNUSR%d to Child.\n", t);
        kill(pid, (t == 1) ? SIGUSR1 : SIGUSR2);
        wait(NULL);
        printf("Parent: Child excited.\n");
    }
    else
    {
        signal(SIGUSR1, childSigHandler);
        signal(SIGUSR2, childSigHandler);
        while (1)
            sleep(1);
    }
    exit(0);
}