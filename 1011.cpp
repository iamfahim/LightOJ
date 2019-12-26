//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ms(a,b)         memset(a, b, sizeof(a))
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout<<"Hello, i am in here."<<endl;
#define bit_cnt(mask) __builtin_popcountll(mask)
#define ll long long int
#define dst(u,v,x,y) sqrt((x*1.0-u*1.0)*(x*1.0-u*1.0)+(y*1.0-v*1.0)*(y*1.0-v*1.0))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}
using namespace std;
const int MOD = (int)1e9+7;
ll cost[20][20];
ll dp[65540];
ll solve(ll n)
{
    ll two=2;
    for(ll i=0;i<(ll)bpow(two,n);i++)
    {
      dp[i]=0;
    }
    for(ll mask=0;mask<(ll)bpow(two,n);mask++)
    {
      ll x=bit_cnt(mask);
      for(ll j=0;j<n;j++)
      {
          if((mask&1<<j)==0)
          {
              dp[mask|1<<j]=max(dp[mask|1<<j],dp[mask]+cost[x][j]);
          }
      }
    }
    return dp[(ll)bpow(two,n)-1];
}
int  main()
{
    ll TestCase,Case=0;
    scanf("%lld",&TestCase);
    while(TestCase--)
    {
         ll n;
        scanf("%lld",&n);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            scanf("%lld",&cost[i][j]);
        }
    }
    ll ans=solve(n);
    printf("Case %lld: %lld\n",++Case,ans);
    }
    return 0;
}

