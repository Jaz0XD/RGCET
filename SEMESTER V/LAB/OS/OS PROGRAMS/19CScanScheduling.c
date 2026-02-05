#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int left = 0, hr, right = 0, start = 0, i, j, h, end, n, a[20], b[20], temp, post;
    clrscr();
    printf(“ C – SCAN SCHEDULING “);
    printf(“\n\nEnter the Ending Position of the Disc : “);
    scanf(“% d”, &end);
    printf(“\nEnter the Number of Cylinders : “);
    scanf(“% d”, &n);
    printf(“\nEnter the Cylinder Values between 0 and % d : \n”, end);
    for (i = 1; i <= n; i++)
        scanf(“% d”, &a[i]);
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf(“\nEnter the Starting Head Position : “);
    scanf(“% d”, &h);
    hr = h;
    for (i = 1; i <= n; i++)
    {
        if (h < a[i])
            break;
    }
    post = i;
    printf(“The Order of Visiting the Cylinders : \n”);
    for (i = post; i <= n; i++)
    {
        right = right + abs(h - a[i]);
        h = a[i];
        printf(“\t % d”, h);
    }
    right = right + abs(h - end);
    printf(“\t % d”, end);
    right = right + abs(end - start);
    h = start;
    for (i = 1; i < post; i++)
    {
        printf(“\t % d”, h);
        right = right + abs(h - a[i]);
        h = a[i];
    }
    printf(“\t % d”, h);
    printf(“\nThe Seek Time is : % d\n\n”, right);
    getch();
}
