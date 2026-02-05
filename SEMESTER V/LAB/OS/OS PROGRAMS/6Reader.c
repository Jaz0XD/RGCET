#include <stdio.h>
#include <conio.h>
void main()
{
    int p[20], s[20], i, no, flag, rd[20], count;
    printf("\nREADER-WRITER PROBLEM\n");
    printf("\nEnter the process Number..");
    scanf("%d", &no);
    printf("--------------------------------------------");
    printf("\n\t0---READING");
    printf("\n\t1---WRITING");
    printf("\n--------------------------------------------");
    for (i = 1; i <= no; i++)
    {
        printf("\nValue of process Id...");
        scanf("%d", &p[i]);
        printf("\nStatus of Process Id...");
        scanf("%d", &s[i]);
    }
    printf("\nProcess Id\tStatus");
    for (i = 1; i <= no; i++)
    {
        printf("\n%d\t\t%d", p[i], s[i]);
    }
    printf("\n\n\nWriters list");
    flag = 0;
    for (i = 1; i <= no; i++)
    {
        if (s[i] == 1)
        {
            flag = 1;
            printf("\nProcess Id %d", p[i]);
            count++;
            while (count != 0)
            {
                count--;
            }
        }
        else
        {
            rd[i] = p[i];
        }
    }
    if (flag == 1)
        printf("\nWriting is completed");
    else
        printf("\nno Writing Process");
    printf("\n\n\nReaders List");
    flag = 0;
    for (i = 1; i <= no; i++)
    {
        if (s[i] != 1)
        {
            flag = 1;
            printf("\nProcess Id=%d", rd[i]);
        }
    }
    if (flag == 0)
    {
        printf("\nNo Reading Process");
    }
}
