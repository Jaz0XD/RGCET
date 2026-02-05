#include <stdio.h>
#include <conio.h>
void main()
{
    int i, z = 1, z1, n, n1, awt, p[10], j[10], t[10], t1[10], b[10], w[10], b1[10], b2[10];
    int temp[10], m = 0, ts;
    float aw = 0.0, at = 0.0;
    printf("\n\t\t ROUND ROBIN SCHEDULING\n");
    printf("\n enter the number of processes:");
    scanf("%d", &n);
    n1 = n;
    printf("\n enter the time slice:");
    scanf("%d", &ts);
    for (i = 1; i <= n; i++)
    {
        printf("\n enter the burst time for p%d:", i);
        scanf("%d", &b[i]);
        b1[i] = b2[i] = b[i];
        p[i] = i;
        temp[i] = 0;
        w[i] = 0;
        t[i] = 0;
    }
    printf("\n\n\t\t GANTT CHART\n");
    printf("\n--------------------------------------------------\n");
    while (n1 != 0)
    {
        for (i = 1; i <= n; i++)
            if (b1[i] > ts)
            {
                m = m + ts;
                t1[z] = m;
                b1[i] = b1[i] - ts;
                printf("\t p%d", p[i]);
                temp[i]++;
                z++;
            }
            else if (b1[i] != 0)
            {
                n1--;
                w[i] = m - temp[i] * ts;
                printf("\t p%d", p[i]);
                aw += w[i];
                m += b1[i];
                t1[z] = m;
                t[i] = m;
                at = at + t[i];
                b1[i] = 0;
                z++;
            }
    }
    printf("\n-----------------------------------------------------\n");
    z1 = z;
    printf("\n0");
    for (i = 1; i < z1; i++)
        printf("\t %d", t1[i]);
    printf("\n------------------------------------------------------\n");
    printf("\n\n PROCESS\t BURST TIME\t WAITING TIME\tTURN AROUND TIME\n");
    for (i = 1; i <= n; i++)
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t\n", p[i], b[i], w[i], t[i]);
    at /= n;
    aw /= n;
    printf("\n the average waiting time:%fms", aw);
    printf("\n the average turn around time:%fms", at);
    getch();
}
