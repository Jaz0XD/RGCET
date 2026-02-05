#include<iostream.h>
int n, mark[20], adj[50][50], i, j;
class dfs
{
    public:
    void getdata(void);
    void src(int);

};
void dfs:: src(int v)
{
    int w;
    mark[v] = 1;
    cout << "\n visited node: "<< v;
    for(w=1;w< = n; w++)
    if((mark[w] ==0) && (adj[v][w] == 1)) src(w);

}
void dfs:: getdata(void)
{
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout<< "\nEnter 1 if there is direct path else enter 0:\n";
    for(i=1;i<=n;i++)
    {
        for(j=j+1; j<=n;j++)
        {
            cout << "\nVertex" << i << "to" <<j << ":";
            cin >> adj[i][j];
        }
    }
}
int main()
{
    dfs d;
    d.getdata();
    for (i =1; i<= n ; i++)
    mark[i] = 0;
    d.src(1);
    return 0;
}