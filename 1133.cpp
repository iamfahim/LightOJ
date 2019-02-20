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
int  main()
{
    IOS
    ll t;
    cin>>t;
    ll Case=0;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>v;
        ll a;
        for(ll i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        ll mat[120][5];
        char ar[120];
        for(ll i=0;i<m;i++)
        {
            cin>>ar[i];
            if(ar[i]=='R')
            {
                continue;
            }
            else if(ar[i]=='P')
            {
                cin>>mat[i][0]>>mat[i][1];
            }
            else
            {
                cin>>mat[i][0];
            }
        }
        for(ll i=0;i<m;i++)
        {

           if(ar[i]=='R')
           {
               reverse(v.begin(),v.end());
           }
           else if(ar[i]=='M')
           {
               for(ll j=0;j<n;j++)v[j]*=mat[i][0];
           }
           else if(ar[i]=='D')
           {
               for(ll j=0;j<n;j++)v[j]/=mat[i][0];
           }
           else if(ar[i]=='S')
           {
               for(ll j=0;j<n;j++)v[j]+=mat[i][0];
           }
           else
           {
               swap(v[mat[i][0]],v[mat[i][1]]);
           }
        }
        printf("Case %lld:\n",++Case);
        for(ll i=0;i<n-1;i++)
        {
            printf("%lld ",v[i]);
        }
        printf("%lld\n",v[n-1]);
    }
    return 0;
}
