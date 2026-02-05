#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, b[20], sb[20], t[20], n, c[20][20], x;
    clrscr();
    printf("\t\t***CONTIGUOUS FILE ALLOCATION***\n");
    printf("Enter the number of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number of blocks occupied by %d:", i + 1);
        scanf("%d", &b[i]);
        printf("\nEnter the starting block of file %d:", i + 1);
        scanf("%d", &sb[i]);
        t[i] = sb[i];
        for (j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }
    printf("\nFile name\tStart\tBlock Length\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);
    printf("Enter the file name:");
    scanf("%d", &x);
    printf("\nFile name is  %d", x);
    printf("\nLength is  %d", b[x - 1]);
    printf("\nBlocks Occupied..");
    for (i = 0; i < b[x - 1]; i++)
        printf("\t%d", c[x - 1][i]);
    getch();
    return 0;
}
