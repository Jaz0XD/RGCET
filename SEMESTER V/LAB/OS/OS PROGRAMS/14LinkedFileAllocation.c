#include <stdio.h>
#include <conio.h>
struct fileno
{
    char fname[10];
    int start, size, block[10];
} f[10];
int main()
{
    int i, j, n;
    printf("\n\t\tLINKED FILE ALLOCATION");
    printf("\nEnter the no. of files:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the file name:");
        scanf("%s", &f[i].fname);
        printf("\nEnter the starting block:");
        scanf("%d", &f[i].start);

        f[i].block[0] = f[i].start;
        printf("\nEnter the no. of blocks:");
        scanf("%d", &f[i].size);
        printf("\nEnter the block numbers:");
        for (j = 1; j <= f[i].size; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("\nFile\tStart\tSize\tBlock\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 0; j <= f[i].size - 1; j++)
            printf("%d-->", f[i].block[j]);
        printf("%d(-1)", f[i].block[j]);
        printf("\n");
    }
    getch();
    return 0;
}
