#include <stdio.h>
#include <conio.h>
void main()
{
    int n, i, a[20], b[20], c[20], t = 0, tt = 0, wt = 0;
    float awt, att;
    clrscr();
    printf("\nFIRST COME FIRST SERVE SCHEDULING\n");
    printf("\nEnter the Number of Processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the Burst - Time of Process %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        c[i] = t;
        t = t + a[i];

        b[i] = t;
    }
    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\nP%d\t\t%d\t\t%d\t\t%d", i + 1, a[i], c[i], b[i]);
    for (i = 0; i < n; i++)
        tt = tt + b[i];
    for (i = 0; i < n; i++)
        wt = wt + c[i];
    awt = wt / n;
    printf("\n\nThe Average Waiting Time : %f ms", awt);
    att = tt / n;
    printf("\n\nThe Average Turn Around Time : %f ms\n\n", att);
    printf("\n\t\tGANTT CHART\n\n");
    for (i = 0; i < n; i++)
        printf("\tP%d", i + 1);
    printf("\n--------------------------------------------\n");
    printf("0");
    for (i = 0; i < n; i++)
        printf("\t%d", b[i]);
    printf("\n--------------------------------------------\n");
    getch();
}
