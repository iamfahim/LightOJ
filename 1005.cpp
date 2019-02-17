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
    ull Case=0;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k>n)
        {
            printf("Case %lld: 0\n",++Case);
            continue;
        }
        ll nc[n+1],np[n+1],cr[k+1],ncnmr[n-k+1],npnmr[n-k+1];
        for(ll i=1; i<=n; i++)
        {
            nc[i]=i;
            np[i]=i;
        }
        for(ll i=1; i<=k; i++)
        {
            cr[i]=i;
        }
        for(ll i=1; i<=(n-k); i++)
        {
            ncnmr[i]=i;
            npnmr[i]=i;
        }
        for(ll i=1; i<=k; i++)
        {
            if(cr[i]==nc[i])
            {
                cr[i]=1;
                nc[i]=1;
                continue;
            }
            if(cr[i]==np[i])
            {
                cr[i]=1;
                np[i]=1;
                continue;
            }

        }
        for(ll i=1; i<=(n-k); i++)
        {
            if(ncnmr[i]==nc[i])
            {
                ncnmr[i]=1;
                nc[i]=1;
                continue;
            }
            if(ncnmr[i]==np[i])
            {
                ncnmr[i]=1;
                np[i]=1;
                continue;
            }

        }
        for(ll i=1; i<=(n-k); i++)
        {
            if(npnmr[i]==nc[i])
            {
                npnmr[i]=1;
                nc[i]=1;
                continue;
            }
            if(npnmr[i]==np[i])
            {
                npnmr[i]=1;
                np[i]=1;
                continue;
            }

        }
        ll tam=1,tam2=1;
        for(ll i=1; i<=n; i++)
        {
            tam*=(nc[i]);
        }
        for(ll i=1; i<=(n-k); i++)
        {
            tam2*=(npnmr[i]);
        }
        ll pro=(tam/tam2);
        for(ll i=1; i<=n; i++)
        {
            pro*=(np[i]);
        }
        ll pro2=1;
        for(ll i=1; i<=k; i++)
        {
            pro2*=cr[i];
        }
        for(ll i=1; i<=(n-k); i++)
        {
            pro2*=ncnmr[i];
        }
        printf("Case %lld: %lld\n",++Case,(pro/pro2));
    }
    return 0;
}
