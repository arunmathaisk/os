#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define BUFSIZE 80
int main()
{
    int fd[2], n = 0;
    char line[BUFSIZE];

    pipe(fd);

    if (fork() == 0)
    {

        close(fd[0]);
        for (int i = 0; i < 10; i++)
        {
            sprintf(line, "%d", n);
            write(fd[1], line, BUFSIZE);
            printf("Child writes: %d\n", n);
            n++;
            sleep(2);
        }
    }
    else
    {
        close(fd[1]);
        for (int i = 0; i < 10; i++)
        {
            read(fd[0], line, BUFSIZE);
            sscanf(line, "%d", &n);
            printf("Parent reads: %d\n", n);
        }
    }
    return 0;
}