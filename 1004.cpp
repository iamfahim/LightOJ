//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define ll                      long long int
#define ull                     unsigned long long
#define pb                      push_back
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define IOS                     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mk                      make_pair
#define inf                     1LL<<62
#define check                   cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
ll n;
int  main()
{
    IOS
    ll t;
    scanf("%lld",&t);
    ll Case=0;
    while(t--)
    {
       ll MX=0;
        scanf("%lld",&n);
        ll mat[2*n][2*n]={0};
        ll dp[2*n][2*n]={0};
        ll mx=0;
        ll index;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=i; j++)
            {
                scanf("%lld",&mat[i][j]);
            }
        }
        ll loop=n-1;
        ll ctn=0;
        for(ll i=n+1; i<=2*n-1; i++)
        {
            ++ctn;
            ll ctn2=0;
            for(ll j=ctn+1; ; j++)
            {
                scanf("%lld",&mat[i][j]);
                ctn2++;
                if(ctn2>=loop)break;
            }
            loop--;
        }
        ll indexi=1,indexj=1;
        dp[1][1]=mat[1][1];
        MX=max(MX,dp[1][1]);
        for(ll i=1;i<=2*n-2;i++)
        {
           for(ll j=1;j<=i;j++)
           {
               ll tamdp1=mat[i+1][j]+dp[i][j];
               ll tamdp2=mat[i+1][j+1]+dp[i][j];
               dp[i+1][j]=max(tamdp1,dp[i+1][j]);
               dp[i+1][j+1]=max(tamdp2,dp[i+1][j+1]);
               MX=max(MX,dp[i+1][j]);
               MX=max(MX,dp[i+1][j+1]);
           }
        }

        printf("Case %lld: %lld\n",++Case,MX);
    }
    return 0;
}
