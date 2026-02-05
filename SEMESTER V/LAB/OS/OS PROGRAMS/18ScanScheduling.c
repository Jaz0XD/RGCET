#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hr, right = 0, i, j, h, end, n, a[20], temp, post, left = 0, start = 0;
    printf("\t\t**SCAN SCHEDULING**\n");
    printf("\nEnter the ending position of disk:\n");
    scanf("%d", &end);
    printf("\nEnter the number of cylinders:\n");
    scanf("%d", &n);
    printf("\nEnter the cylinder value between 0 and %d...\n", end);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nEnter the head position:\n");
    scanf("%d", &h);
    hr = h;
    for (i = 1; i <= n; i++)
    {
        if (h < a[i])
            break;
    }
    post = i;
    printf("\nMoving in the right side:\n");
    printf("\nThe order of visiting the cylinders:\n");
    for (i = post; i <= n; i++)
    {
        right = right + abs(h - a[i]);
        h = a[i];
        printf("\t%d", h);
    }
    right = right + abs(h - end);
    h = end;
    for (i = post - 1; i >= 1; i--)
    {
        printf("\t%d", h);
        right = right + abs(h - a[i]);
        h = a[i];
    }
    printf("\t%d", h);
    printf("\nThe seek time is:%d\n", right);
    printf("\nMoving in the left side:\n");
    printf("\nThe order of visiting the cylinder:\n");
    for (i = post - 1; i >= 1; i--)
    {
        left = left + abs(hr - a[i]);
        hr = a[i];
        printf("\t%d", hr);
    }
    left = left + abs(hr - start);
    hr = start;
    for (i = post; i <= n; i++)
    {
        printf("\t%d", hr);
        left = left + abs(hr - a[i]);
        hr = a[i];
    }
    printf("\t%d", hr);
    printf("\nThe seek time is:%d\n", left);
    getch();
    return 0;
}
