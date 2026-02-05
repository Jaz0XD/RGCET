#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m[20], i, j, sb[20], b[20][20], x;
    printf("\t\t***INDEXED FILE ALLOCATION***");
    printf("\nEnter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter index %d:", i + 1);
        scanf("%d", &sb[i]);
        printf("\nEnter no. of blocks occupied by file %d:", i + 1);
        scanf("%d", &m[i]);
        printf("\nEnter blocks of file %d:", i + 1);
        for (j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }
    printf("\nFile\tIndex\tLength\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
    }
    printf("\nEnter file name:");
    scanf("%d", &x);
    printf("\nFile name is:%d", x);
    i = x - 1;
    printf("\nIndex is:%d", sb[i]);
    printf("\nBlocks occupied are:");
    for (j = 0; j < m[i]; j++)
        printf("\t%d", b[i][j]);
    getch();
    return 0;
}
