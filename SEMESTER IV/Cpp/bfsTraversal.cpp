#include<iostream.h>

int i,j,n,a[50], mark[20], adj[50][50], top = 0;
int del();
void add(int temp)
{
    a[++top]= temp;

}
int del()
{
    int temp;
    temp = a[1];
    for (i =1;i<top; i++)
    a[i] = a[i+1];
    top--;
    return(temp);
}
void bfs(int v)
{
    int w, u;
    mark[v] = 1;
    add(v);
    while(top!=0)
    {
        u = del();
        cout << "\n\nVISIT NODE = " << u;
        for(w=1;w<n;w++)
        if((mark[w] == 0) &&(adj[v][w] == 1))
        {
            mark[w]= 1;
            add(w);

        }
    }
}
void main()
{
    cout << "\n\n Breadth First Search";
    cout << "\n Enter the no. of nodes";
    cin >> n;
    cout << "\n Enter 1 if there is an edge between nodes else type 0";
    for (i=1; i<=n;i++)
    {
        for ( j= i+1; j<=n; i++)
        {
            cout << "\n\nnode"<< "to node"<< j << "=";
            cin >> adj[i][j];
        }
    }
    for (i =1; i<=n ; i++)
    mark[i] = 0;
    for(i =1; i<=n; i++)
    if(mark[i] ==0)
    bfs(i);

}