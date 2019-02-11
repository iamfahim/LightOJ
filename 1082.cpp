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
    ll t;
    scanf("%lld",&t);
    ll Case=0;
    while(t--)
    {
        ll N,q;
        scanf("%lld %lld",&N,&q);
        vector<pair<ll,ll> >v;
        ll a;
        for(ll i=1;i<=N;i++)
        {
            scanf("%lld",&a);
            v.push_back(make_pair(a,i));
        }
        sort(v.begin(),v.end());
        ll x,y;
        printf("Case %lld:\n",++Case);
        for(ll i=1;i<=q;i++)
        {
            scanf("%lld %lld",&x,&y);
            for(ll j=0;j<N;j++)
            {
                if(v[j].second>=x && v[j].second<=y)
                {
                    printf("%lld\n",v[j].first);
                    break;
                }
            }
        }

    }
    return 0;
}
