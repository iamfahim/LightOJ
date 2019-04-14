#include<bits/stdc++.h>
using namespace std;
int visited[105];
vector<int>edge[105];
vector<int>cost[105];
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct data
{
    int v, w;
    bool operator < (data p) const {
        return w < p.w;
    }
};
struct Data{
    int v,w;
    bool operator < (Data p) const {
    return w>p.w;
    }
};
int MST_prims_max(int src, int n)
{
    memset(visited, 0, sizeof(visited));
    priority_queue<data>pq;
    int u, v, p, sum = 0;

    for(int i = 0; i < n-1; i++)
    {
        u = src;
        visited[src] = 1;

        for(int j = 0; j < edge[u].size(); j++)
        {
            v = edge[u][j];
            if(visited[v] == 0)
            {
                data D;
                D.v = v;
                D.w = cost[u][j];
                pq.push(D);
            }
        }

        while(visited[src])
        {
            data T = pq.top(); pq.pop();
            src = T.v;
            p = T.w;
        }
        sum += p;
    }
    return sum;
}
int MST_prims_min(int src, int n)
{
    memset(visited, 0, sizeof(visited));
    priority_queue<Data>pq;
    int u, v, p, sum = 0;

    for(int i = 0; i < n-1; i++)
    {
        u = src;
        visited[src] = 1;

        for(int j = 0; j < edge[u].size(); j++)
        {
            v = edge[u][j];
            if(visited[v] == 0)
            {
                Data D;
                D.v = v;
                D.w = cost[u][j];
                pq.push(D);
            }
        }

        while(visited[src])
        {
            Data T = pq.top(); pq.pop();
            src = T.v;
            p = T.w;
        }
        sum += p;
    }
    return sum;
}
int main()
{
    IOS
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
    int n, e, u, v, w;
    scanf("%d", &n);
    n++;
   while(scanf("%d %d %d",&u,&v,&w)!=EOF){
        if(u==0 && v==0 && w==0)break;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int mx=MST_prims_max(0, n);
    int mn=MST_prims_min(0,n);
    if((mx+mn)%2!=0)
    {
        printf("Case %d: %d/2\n",++Case,(mx+mn));
    }
    else
    {
        printf("Case %d: %d\n",++Case,(mx+mn)/2);
    }
    for(int i=0;i<105;i++)
    {
        cost[i].clear();
        edge[i].clear();
    }
    }
    return  0;
}
