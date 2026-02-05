#include <stdio.h>
#include <conio.h>
#define max 25
void main()
{
    int frame[10], length[10], index, highest;
    int i, j, k, n, nf, page[max], temp;
    int flag = 0, pf = 0, found = 0;
    printf("\n\toptimal PAGE REPLACEMENT\n");
    printf("\nEnter no. of frames:");
    scanf("%d", &nf);
    for (i = 0; i < nf; i++)
        frame[i] = -1;
    printf("\nEnter the no. of ref string:");
    scanf("%d", &n);
    printf("\nEnter the ref string:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    printf("\n\tRef.String\tPage\t Frames\n");
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < nf; j++)
        {
            if (frame[j] == page[i])
            {
                printf("\n%d\t\t", page[i]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (j = 0; j < nf; j++)
            {
                for (temp = i + 1; temp < n; temp++)
                {
                    length[j] = 0;
                    if (frame[j] == page[temp])
                    {
                        length[j] = temp - i;
                        break;
                    }
                }
            }
            found = 0;
            for (j = 0; j < nf; j++)
            {
                if (length[j] == 0)
                {
                    index = j;
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                highest = length[0];
                index = 0;
                for (j = 1; j < nf; j++)
                {
                    if (highest < length[j])
                    {
                        highest = length[j];
                        index = j;
                    }
                }
            }
            frame[index] = page[i];
            printf("\n%d\t\t", page[i]);
            pf++;
            for (k = 0; k < nf; k++)
                printf("%d\t", frame[k]);
        }
    }
    printf("\nNumber of page fault is:%d\n\n", pf);
    getch();
}
