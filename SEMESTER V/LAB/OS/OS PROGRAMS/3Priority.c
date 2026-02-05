#include <stdio.h>
#include <conio.h>
void main()
{
    int i, j, n, p[10], c[10], wt, tt, t1, t2, b[10], pro[10], tp, b1[10], ch, tb;
    float awt = 0.0, s = 0.0, avg = 0.0, t = 0.0;
    printf("\t\tPRIORITY SCHEDULING\n");
    printf("\nEnter the number of processes:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nPROCESS%d: \nPRIORITY:", i);
        scanf("%d", &p[i]);
        printf("\nBURST TIME:");
        scanf("%d", &c[i]);
        b[i] = p[i];
        b1[i] = p[i];
    }
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (p[i] > p[j])
            {
                t1 = c[i];
                c[i] = c[j];
                c[j] = t1;
                t2 = p[i];
                p[i] = p[j];
                p[j] = t2;
                tp = pro[i];
                pro[i] = pro[j];
                pro[j] = tp;
                tb = b[i];
                b[i] = b[j];
                b[j] = tb;
            }
    i = 1;
    j = 1;
    while (i <= n)
    {
        if (p[i] == b1[j] && ch != j)
        {
            p[i] = j;
            pro[i] = j;
            ch = j;
            i++;
            j = 0;
        }
        j++;
    }
    wt = 0;
    c[0] = 0;
    tt = 0;
    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        wt = wt + c[i];
        tt = tt + c[i + 1];
        printf("\n\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pro[i + 1], b[i + 1], c[i + 1], wt, tt);
        awt = awt + wt;
        avg = avg + tt;
    }
    s = awt / n;
    t = avg / n;
    printf("\n\nTHE AVERAGE WAITING TIME:%f ms", s);
    printf("\n\nTHE AVERAGE TURN AROUND TIME:%f ms", t);
    printf("\n\n\t\tGANTT CHART \n\n");
    wt = 0;
    printf("\n------------------------------------\n");
    printf("0");
    for (i = 0; i <= n; i++)
    {
        wt = wt + c[i];
        printf("%d\t", wt);
    }
}
