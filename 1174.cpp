//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int  main()
{
    IOS
    ll t;
    cin>>t;
    ll Case=0;
    while(t--)
    {
        ll g[105][105];
        for(ll i=0;i<105;i++)
        {
            for(ll j=0;j<105;j++)
            {
                if(i==j)g[i][j]=0;
                else g[i][j]=INT_MAX;
            }
        }
        ll n,e,s,d,u,v;
        cin>>n>>e;
        for(ll i=0;i<e;i++)
        {
            cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }
        cin>>s>>d;
        for(ll k=0;k<n;k++)
        {
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n;j++)
                {
                    if(g[i][j]>g[i][k]+g[k][j])g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
        ll mx=g[s][0]+g[0][d];
        for(ll i=1;i<n;i++)
        {
            mx=max(mx,g[s][i]+g[i][d]);
        }
        printf("Case %lld: %lld\n",++Case,mx);

    }
    return 0;
}
