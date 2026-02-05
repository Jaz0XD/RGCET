#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
int h, a[20], b = 0, i, j, n;
void main()
{
    printf("FIRST COME FIRST SERVE DISK SCHEDULING\n");
    printf("\nEnter the Number of Cylinder : ");
    scanf("%d", &n);
    printf("\nEnter the Cylinder Values : \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the Starting Head Position : ");
    scanf("%d", &h);
    printf("\nThe Order of Visiting the Cylinders:\n");
    for (i = 1; i <= n; i++)
        printf("\t%d", a[i]);
    for (i = 1; i <= n; i++)
    {
        b += abs(h - a[i]);
        h = a[i];
    }
    printf("\nThe Seek Time is %d Cylinders", b);
    getch();
}
