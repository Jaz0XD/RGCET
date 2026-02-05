#include <stdio.h>
#include <stdlib.h>
int i, n;
struct f
{
    int nm, r;
} h[25];
int fit()
{
    printf("\n enter the total no.of blocks and holes:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
    xx:
        printf("\n enter whether it is block or holes:");
        scanf("%d", &h[i].nm);
        if ((h[i].nm != 1) && (h[i].nm != 2))
        {
            printf("\n enter the name is invalid try again");
            goto xx;
        }
        printf("\n enter the size:");
        scanf("%d", &h[i].r);
    }
    return 0;
}
int ffit(int x)
{
    for (i = 0; i <= n; i++)
    {
        if ((h[i].nm == 2) && (x <= h[i].r))
        {
            printf("\n allocation of block %d by first fit:", x);
            printf("%d", h[i].r);
            break;
        }
    }
    if (i == n + 1)
        printf("\n first fit:");
    return 0;
}
int wfit(int x)
{
    int t = 0;
    for (i = 0; i <= n; i++)
    {
        if ((h[i].nm == 2) && (x <= h[i].r) && (t < h[i].r))
            t = h[i].r;
    }
    printf("\n allocation of block %d by worst fit:", x);
    printf("%d", t);
    return 0;
}
int bfit(int x)
{
    int temp[25], k = 1;
    for (i = 1; i <= n; i++)
    {
        if ((h[i].nm == 2) && (x <= h[i].r))
        {
            temp[k] = h[i].r;
            k++;
        }
    }
    for (i = 1; i < k; i++)
    {
        int j;
        for (j = i + 1; j < k; j++)
        {
            if (temp[i] > temp[j])
            {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    printf("\n allocation of bloack %d by best fit:", x);
    printf("%d", temp[1]);
    return 0;
}
int show()
{
    printf("\n allocation of block and holes \n");
    for (i = 1; i <= n; i++)
    {
        if (h[i].nm == 1)
        {
            printf("block(%d)\n", h[i].r);
        }
        else
        {
            printf("hole(%d)\n", h[i].r);
        }
    }
    return 0;
}
int main()
{
    int b;
    printf("\n block =1\n");
    printf("\n hole=2\n");
    fit();
    show();
    printf("\n enter the block to be inserted:");
    scanf("%d", &b);
    ffit(b);
    bfit(b);
    wfit(b);
    return 0;
}
