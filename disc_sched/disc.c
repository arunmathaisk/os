#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
    int i, sum = 0, n, st;
    int a[20], b[20], dd[20];
    do
    {
        printf("\nEnter the block number between 0 and 200: ");
        scanf("%d", &st);
    } while ((st >= 200) || (st < 0));
    printf("\nOur disk head is on the %d block", st);
    a[0] = st;
    printf("\nEnter the no. of request: ");
    scanf("%d", &n);
    printf("\nEnter request: ");
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter %d request: ", i);
        scanf("%d", &a[i]);
        do
        {
            if ((a[i] > 200) || (a[i] < 0))
            {
                printf("\nBlock number must be between 0 and 200!");
            }
        } while ((a[i] > 200) || (a[i] < 0));
    }
    for (i = 0; i <= n; i++)
        dd[i] = a[i];
    printf("\n\t\tFIRST COME FIRST SERVE: ");
    printf("\nDISK QUEUE:");
    for (i = 0; i <= n; i++)
        printf("\t%d", a[i]);
    printf("\n\nACCESS ORDER:");
    for (i = 0; i <= n; i++)
    {
        printf("\t%d", dd[i]);
        if (i != n)
            sum += abs(dd[i] - dd[i + 1]);
    }
    printf("\n\nTotal no. of head movements: %d", sum);
}