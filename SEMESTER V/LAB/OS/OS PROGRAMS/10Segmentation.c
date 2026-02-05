#include <stdio.h>
#include <conio.h>
int main()
{
    int n, x, y, sc, pa, ba, ab, li, b[10], l[10], i[10], j;
    y = y - 1;
    printf("\n\t\tSIMULATION OF SEGMENTATION\n");
    printf("\nEnter the Number of Entries : ");
    scanf("%d", &n);
    for (x = 0; x < n; x++)
    {
        printf("SEGMENT NO:");
        scanf("%d", &i[x]);
        printf("LIMIT:");
        scanf("%d", &l[x]);
        printf("BASE:");
        scanf("%d", &b[x]);
    }
    printf("\nEnter the Segment No.: ");
    scanf("%d", &sc);
    for (j = 0; j < n; j++)
        if (i[j] == sc)
        {
            y = 1;
            ba = b[j];
            li = l[j];
        }
    if (y < 0)
    {
        printf("\nINVALID SEGMENT\n");
    }
    printf("\nEnter the Byte to be Referenced : ");
    scanf("%d", &ab);
    if (ab > li)
    {
        printf("\nCannot Find this Address :");
        printf("\nLimit Only %d", i);
    }
    pa = ba + ab;
    printf("\nThe Physical Address is : ");
    printf("%d\n", pa);
    getch();
}
