#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Program to demonstrate Exec\n");
    execlp("cal", "cal", "2012", NULL);

    printf("This statement will not be executed");
    return 0;
}