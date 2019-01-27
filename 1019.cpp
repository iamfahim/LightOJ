//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define ull            unsigned long long
#define min3(a,b,c)    min(a,min(b,c))
#define min4(a,b,c,d)  min(a,min(b,min(c,d)))
#define max3(a,b,c)    max(a,max(b,c))
#define max4(a,b,c,d)  max(a,max(b,max(c,d)))
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
#define mx 1010
vector<ll>g[mx];
vector<ll>cost[mx];
ll d[mx];
ll par[mx];
struct node
{
   ll city,dist;
   node(int a,int b)
   {
       city=a;
       dist=b;
   }
   bool operator< (const node& p) const
   {
       return p.dist<dist;
   }
};
ll dijkstra(ll src,ll des)
{
    for(ll i=0;i<mx;i++)
    {
        d[i]=inf;
    }
    memset(par,-1,sizeof(par));
    priority_queue<node>q;
    d[src]=0;
    q.push(node(src,0));
    while(!q.empty())
    {
        node top=q.top();q.pop();
        ll u=top.city;
        if(u==des){return d[u];}
        for(int i=0;i<g[u].size();i++)
        {
            ll v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }

    }
    return -1;
}
int main()
{
    IOS
    ll t;
    ll Case=0;
    scanf("%lld",&t);
    while(t--)
    {
    ll n,e;
    scanf("%lld %lld",&n,&e);
    for(ll i=0;i<e;i++)
    {
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    ll ret=dijkstra(1,n);
    if(ret==-1)
    {
        printf("Case %lld: Impossible\n",++Case);
    }
    else
    {
            printf("Case %lld: %lld\n",++Case,d[n]);
    }
    for(ll i=0;i<mx;i++)
    {
        g[i].clear();
        cost[i].clear();
    }
    }
    return 0;
}
