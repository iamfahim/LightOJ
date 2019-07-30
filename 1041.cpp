//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int visited[102];
int vis[102];
vector<int>edge[102];
vector<int>cost[102];
void dfs(int s)
{
    if(vis[s])return;
    vis[s]=1;
    for(int i=0;i<edge[s].size();i++)
    {
        dfs(edge[s][i]);
    }

}
struct data
{
    int v, w;
    bool operator < (data p) const {
        return w > p.w;
    }
};
int MST_prims(int src, int n)
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
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    int Case=0;
    cin>>t;
    while(t--)
    {
        ms(vis,0);
       int m,w,node=1;
       int a,b;
       int n=0;
       string s1,s2;
       map<string,int>mp;
       cin>>m;
       for(int i=1;i<=m;i++){
       cin>>s1>>s2>>w;
        if(!mp[s1]){
            mp[s1]=node++;
            n++;
        }
        if(!mp[s2])
        {
            mp[s2]=node++;
            n++;
        }
        a=mp[s1];
        b=mp[s2];
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
       }
       dfs(1);
       bool ok=false;
       for(int i=1;i<=n;i++)
       {
          if(vis[i]==0){
            ok=true;
            break;
          }
       }
       if(ok)
       {
           printf("Case %d: Impossible\n",++Case);
       }
       else{
       int ans=MST_prims(1,n);
       printf("Case %d: %d\n",++Case,ans);
       }
       for(int i=0;i<102;i++)
       {
           edge[i].clear();
           cost[i].clear();
       }
    }
    return 0;
}
