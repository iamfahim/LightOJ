#include<bits/stdc++.h>
using namespace std;
#define mx 30005
#define inf 0
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>g[mx];
int n;
vector<int>cost[mx];
int d[mx]= {0};
int p[mx];
int visited[mx]= {0};
vector<pair<int ,int> >ans;
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    d[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                d[v]=d[u]+cost[u][i];
                q.push(v);

            }
        }
        if(g[u].size()==1)ans.push_back(make_pair(d[u],u));

    }
}
int main()
{
    IOS
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    int Case=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n-1; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int node;
        for(int i=0; i<n-1; i++)
        {
            if(g[i].size()==1)
            {
                node=i;
                break;
            }
        }
        bfs(node);
        sort(ans.rbegin(),ans.rend());
        int st=ans[0].second;
        for(int i=0; i<mx; i++)
        {
            visited[i]=0;
            d[i]=0;
        }
        ans.erase(ans.begin(),ans.begin()+ans.size());
        bfs(st);
        sort(ans.rbegin(),ans.rend());
        printf("Case %d: %d\n",++Case,ans[0].first);
        for(int i=0; i<mx; i++)
        {
            g[i].clear();
            cost[i].clear();
            visited[i]=0;
            d[i]=0;
        }
        ans.erase(ans.begin(),ans.begin()+ans.size());
    }
    return 0;
}

