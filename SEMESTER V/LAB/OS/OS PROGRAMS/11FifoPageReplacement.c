#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i, j, a[50], frame[10], n, no, k, avail, count = 0;
    printf("\n***FIFO PAGE REPLACEMENT ***");
    printf("\n Enter the number of reference string:\n");
    scanf("%d", &n);
    printf("Enter the page number:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the number of frames:");
    scanf("%d", &no);
    for (i = 0; i <= no; i++)
        frame[i] = -1;
    j = 0;
    printf("\n Ref string\tpage frame\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;
        for (k = 0; k <= no; k++)
            if (frame[k] == a[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("\n page fault is %d", count);
    getch();
}
