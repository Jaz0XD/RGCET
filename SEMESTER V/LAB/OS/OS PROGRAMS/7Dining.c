#include <stdio.h>
#include <conio.h>
int st[25], temp[25];
void eating(int, int, int);
void main()
{
    int n = 5, f, i, x, y;
    int ch;
    printf("\n\t\tDINING-PHILOSPER PROBLEM");
xx:
    printf("\nASSUMPTION\n");
    printf("\nHUNGRY==>1\nEATING==>2\nTHINKING==>3\n");
    for (i = 1; i <= n; i++)
        do
        {
            f = 0;
            printf("\nEnter the status of %d :", i);
            scanf("%d", &st[i]);
            if (st[i] > 3 || (st[i] < 1))
            {
                printf("\nEntered philosopher ststus is invalid");
                printf("\nDo you want to try again(Y/N):");
                ch = getch();
                if (ch == 'y' || ch == 'Y')
                    f = 1;
                else
                {
                    f = 0;
                    printf("\nSTOP");
                    getch();
                    exit(1);
                }
            }
        } while (f == 1);
    for (i = 1; i <= n; i++)
    {
        if (i == n)
        {
            x = n;
            y = 1;
        }
        else
        {
            x = i;
            y = i + 1;
        }
        if ((st[x] == 2) && (st[y] == 2))
        {
            printf("\nEntered philosopher stsus id invalid");
            printf("\nSorry try again...");
            goto xx;
        }
    }
    printf("\n\nRESULTS....:");
    for (i = 1; i <= n; i++)
    {
        if (st[i] == 3)
            printf("\nPhilosopher %d is thinking\n", i);
        if (st[i] == 2)
            printf("\nPhilosopher %d id eating\n", i);
        if (st[i] == 1)
        {
            if (i == 1)
                eating(i + 1, i + 4, i);
            else
                eating(i + 1, i - 1, i);
        }
    }
}
void eating(int x, int y, int z)
{
    if (temp[x] == 1)
    {
        printf("\nPhilosopher %d is hungry and cannot eat since %d has the possibility of eating\n", x, z);
        return;
    }
    if (temp[y] == 1)
    {
        printf("\nPhilosopher %d is hungry and cannot eat since %d has the possibility of eating\n", z, y);
        return;
    }
    if ((st[x] != 2) && (st[y] != 2))
    {
        printf("\n\nPhilosopher %d is hungry and cannot eat\n", z);
        st[z] = 2;
        temp[z] = 1;
    }
    if ((st[x] == 2) && (st[y] == 2))
    {
        printf("\n\nPhilosopher %d is hungry but not eatting since neighbours %d, %d are eating\n", z, x, y);
        return;
    }
    if (st[x] == 2)
    {
        printf("\n\nPhilosopher %d is hungry but not eating since neighbours %d, \n", z, x);
        return;
    }
    if (st[y] == 2)
    {
        printf("\n\nPhilosopher %d is hungry but not eating since neighbours %d, \n", z, y);
        return;
    }
}
