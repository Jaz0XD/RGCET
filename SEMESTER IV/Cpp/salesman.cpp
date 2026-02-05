#include <iostream.h>
class sales
{
    int cost[20][20];
    int i,a[20], min, result[20], j,x,n;
    public:
    void input();
    int dts(int v, int t[10], int x, int path[20]);
    void display();

};

void sales::input()
{
    cout << "\nTravelling salesman problem\n";
    cout << "\nEnter the values of n:";
    cin >> n;
    cout << "\nENter the existing path and their distances:";
    cout << "\nFrom to distance\n";
    do
    {
        cin >> i; i--;
        cin >> j; j--;
        if((i==-1) && (j == -1))
        break;
        cin >> cost[i][j];
    } while (1);
    for (i =1 ; i<=n; i++)
    cost [i][j] = 0;
    for(i=0;i<n-1;i++)
    a[i] = i+1;
    min = dts(0, &a[0] ,n-1, & result[0]);    
}

int sales:: dts(int v, int t[10], int x, int path[20])
{
    int a[20], j, k ,min = 999, temp[10], y;
    for (i = 0; i<=x ; i++)
    a[i] = 0;
    if(x == 0)
    {
        *path = v;
        return(cost[v][0]);

    }
    else if (x == 1 )
    {
        path [0] = t[0];
        path [1 ]= 0;
        return (cost [v][t[0]] + cost[t[0]][0]);
    }
    else
    {
        for (i = 0; i< x; i++)
        {
            k = 0;
            for ( j = 0; j< x; j++)
            {
                if(t[j] != t[i])
                {
                    a[k] = t[j];
                    k++;
                }
            }
            y = ( cost[v] [t [i]] + dts(t[i], a, x-1, temp));
            if(min > y)
            {
                path [0] = t[i];
                k = 1;
                min = y;
                for(j=0; j<x;j++)
                {
                    path [k] = temp[j];
                    k++;
                }
            }
        }
    }
    return(min);

}
void sales:: display()
{
    cout << "\nThe resulatant path is: " << endl;
    cout << "l";
    for (i = 0; i<n;i++)
    {
        cout << "---";
        cout << result[i]+1;
    }
    cout << "\n THe total distance: "<< min;

}
void main()
{
    sales t;
    t.input();
    t.display();
}