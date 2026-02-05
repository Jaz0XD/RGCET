#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int sstf();
int seek = 0, t1, t2, n, a[20] = {{0}}, z = 1, d[20] = {{0}}, h = 0;
void main()
{
    int i, j, hr;
    clrscr();
    printf("\t\t SHORTEST SEEK TIME FIRST SCHEDULING \n\n");
    printf("Enter the Number of Cylinders : ");
    scanf("%d", &n);
    printf("\nEnter the Cylinder Values : \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the Starting Head Position : ");
    scanf("%d", &h);
    hr = h;
    printf("\nThe Order of Visiting the Cylinders : \n");
    for (i = 1; i <= n; i++)
        sstf();
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        seek = seek + abs(hr - d[i]);
        hr = d[i];
    }
    printf("\nThe Seek Time is %d", seek);
    getch();
}
int sstf()
{
    int b[20] = {{0}}, c = 1, i, j;
    for (i = 1; i <= n; i++)
        b[i] = abs(h - a[i]);
    for (i = 1; i <= n; i++)
        if (b[c] > b[i])
            c = i;
    printf("\t%d", a[c]);
    h = a[c];
    d[z] = a[c];
    z++;
    a[c] = 9999;
    return (0);
}
