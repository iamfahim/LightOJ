#include<bits/stdc++.h>
using namespace std;
int visited[510];
vector<int>edge[510];
vector<int>cost[510];
vector<int>nedge[510];
vector<int>ncost[510];
vector<int>g[510];
int nvisited[510]={0};
int node=0;
int mat[510][510];
int nnvisited[510]={0};
int value=0;
int dd;
int n, e, u, v, w,d;
bool ok=false;
int par[510];
struct data
{
    int v,u, w;
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
                D.u=u;
                D.v = v;
                D.w = cost[u][j];
                pq.push(D);
            }
        }
        int prsrc,pru;
        while(visited[src])
        {
            data T = pq.top(); pq.pop();
            src = T.v;
            p = T.w;
            pru=T.u;
            //cout<<pru<<" "<<src<<" "<<p<<endl;
        }
     // cout<<"Fahim"<<endl;
        mat[pru][src]=p;
        mat[src][pru]=p;
        g[pru].push_back(src);
        g[src].push_back(pru);
        sum += p;
    }
    return sum;
}
void dfs(int s)
{
   if(nvisited[s])return;
   nvisited[s]=1;
   node++;
   for(int i=0;i<nedge[s].size();i++)
   {
      int u=nedge[s][i];
      int cs=ncost[s][i];
      edge[s].push_back(u);
      edge[u].push_back(s);
      cost[s].push_back(cs);
      cost[u].push_back(cs);
      dfs(u);
   }
}
int bfs(int s)
{
   queue<int>q;
   q.push(s);
   nnvisited[s]=1;
   par[s]=s;
   while(!q.empty())
   {
      int u=q.front();
      q.pop();
      for(int i=0;i<g[u].size();i++)
      {
         if(nnvisited[g[u][i]]==0)
         {
            int v=g[u][i];
            nnvisited[v]=1;
            par[v]=u;
            q.push(v);
         }
      }
   }

}
int main()
{
   //freopen("input.txt","rt",stdin);
   int t;
   int Case=0;
   scanf("%d",&t);
   while(t--){
    scanf("%d %d", &n, &e);
    for(int i = 0; i < e; i++)
    {
         scanf("%d %d %d",&u,&v,&w);
        nedge[u].push_back(v);
        nedge[v].push_back(u);
        ncost[u].push_back(w);
        ncost[v].push_back(w);
    }
    scanf("%d",&d);
    for(int i=0;i<=510;i++)
    {
       for(int j=0;j<=510;j++)
         {
          mat[i][j]=0;

         }
    }
    dfs(d);
    MST_prims(d, node);
   /* for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
         {
            cout<<mat[i][j]<<" ";
         }
         cout<<endl;
    }
*/
   int ans[n+1]={0};
   for(int i=0;i<n;i++)
   {
      if(i==d)ans[i]=0;
      else if(nvisited[i])
      {

          for(int j=0;j<n;j++){
               nnvisited[j]=0;
               par[j]=j;
          }
         bfs(i);
         int now=d;
         //cout<<"Fahim"<<endl;
        // for(int j=0;j<n;j++)cout<<par[j]<<endl;
         while(now!=i)
         {
            value=max(value,mat[now][par[now]]);
            //cout<<"now "<<now<<" par[now] "<<par[now]<<" value "<<value<<endl;
            now=par[now];
           //cout<<now<<endl;
         }
         ans[i]=value;
         value=0;
      }
      else ans[i]=-1;
   }
   /* for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
         {
            cout<<mat[i][j]<<" ";
         }
         cout<<endl;
    }*/
    printf("Case %d:\n",++Case);
    for(int i=0;i<n;i++)
    {
       if(ans[i]==-1)
       {
          printf("Impossible\n");
       }
       else
       {
          printf("%d\n",ans[i]);
       }
    }
    for(int i=0;i<=510;i++)
    {
       g[i].clear();
       nedge[i].clear();
       edge[i].clear();
       nvisited[i]=0;
       nnvisited[i]=0;
       cost[i].clear();
       ncost[i].clear();
    }
   }
    return  0;
}
