#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define INFILENAME "input.c"
#define OUTFILENAME "output.c"
int main()
{
    int ifd, ofd;
    char c;
    ifd = open(INFILENAME, O_RDONLY);
    if (ifd < 0)
    {
        fprintf(stderr, "Error has occurred.\n");
        exit(1);
    }
    else
    {
        fprintf(stderr, "New file descriptor has been found %d\n", ifd);
    }

    ofd = open(OUTFILENAME, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
    if (ofd < 0)
    {
        fprintf(stderr, "Error has occurred.\n");
        exit(1);
    }
    else
    {
        fprintf(stderr, "New file descriptor has been found %d\n", ofd);
    }

    close(0);
    close(1);

    dup(ifd);
    close(ifd);

    dup(ofd);
    close(ofd);

    while (1)
    {
        scanf("%c", &c);
        if (feof(stdin))
            break;
        if ((c >= "a") && (c <= "z"))
            c -= 'a' - 'A';
        printf("%c", c);
    }

    exit(0);
}
