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
vector<ll>g[10005];
ll visited[10005];
ll indeg[10005];
ll outdeg[10005];
ll ctn=0;
bool ok=false;
void dfs(ll s)
{
    //cout<<s<<" "<<indeg[s]<<" ";
    if(visited[s])return;
    visited[s]=1;
   // cout<<s<<" "<<indeg[s];
    if(indeg[s]==0)
    {
        ctn++;
        ok=true;
    }
    for(ll i=0;i<g[s].size();i++)
    {
        ll u=g[s][i];
        dfs(u);
    }
}
int  main()
{
    IOS
    ll t,Case=0;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,m;
        ll a,b;
        vector<pair<ll,ll> >pr;
        vector<pair<ll,ll> >prin;
        ms(indeg,0);
        ms(visited,0);
        ms(outdeg,0);
        scanf("%lld %lld",&n,&m);
        for(ll i=1; i<=m; i++)
        {
            scanf("%lld %lld",&a,&b);
            g[a].push_back(b);
            indeg[b]++;
            outdeg[a]++;
        }
        for(ll i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                prin.push_back(make_pair(outdeg[i],i));
            }
        }
        sort(prin.rbegin(),prin.rend());
        for(ll i=1;i<=n;i++)
        {
            if(indeg[i]!=0){
                pr.push_back(make_pair(outdeg[i],i));
            }
        }
        sort(pr.rbegin(),pr.rend());
        ctn=0;
        for(ll i=0;i<prin.size();i++)
        {
            ok=false;
            if(!visited[prin[i].second])
            {
                dfs(prin[i].second);
                if(!ok)ctn++;
            }
        }
        for(ll i=0;i<pr.size();i++)
        {
            ok=false;
            if(!visited[pr[i].second])
            {
                dfs(pr[i].second);
                if(!ok)ctn++;
            }
        }
        for(ll i=1; i<=n; i++)
        {
            ok=false;
             if(!visited[i])
            {
                dfs(i);
                if(!ok){ctn++;}
                i=1;
            }

        }
        printf("Case %lld: %lld\n",++Case,ctn);
        for(ll i=0;i<=10000;i++)
        {
            g[i].clear();
        }
    }
    return 0;
}
