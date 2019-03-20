#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;
#define Max_size 105
ll graph[Max_size][Max_size];
ll visited[Max_size];
ll flag[Max_size][Max_size];
ll ctn=0;
ll n;
void dfs(int s)
{
    if(visited[s])return;
    for(ll i=1;i<=100;i++)
    {
        visited[s]=1;
        if(flag[s][i]){

                if(graph[s][i]!=0)
                {

                    ctn+=graph[s][i];
                }
                flag[s][i]=flag[i][s]=0;
            dfs(i);
        }
    }
}
int main()
{
    IOS
    ll T;
    cin>>T;
    ll Case=0;
    while(T--)
    {
        for(ll i=1;i<=100;i++)
        {
            visited[i]=0;
            for(ll j=1;j<=100;j++)
            {
                graph[i][j]=flag[i][j]=0;
            }
        }
        cin>>n;
        ll sum=0;
        for(ll i=0; i<n; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
             graph[u][v]=w;
             flag[u][v]=flag[v][u]=1;
            sum+=w;
        }
        ctn=0;
        dfs(1);
        ll ans1=sum-ctn;
        ll ans2=ctn;
        printf("Case %lld: %lld\n",++Case,min(ans1,ans2));
    }
    return 0;
}
