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
ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                cnt++;
            }
            else{
                cnt = cnt + 2;
            }
        }
    }
    return cnt;
}
int  main()
{
    IOS
    vector<pair<ll,ll> >vp;
    for(ll i=1;i<=1000;i++)
    {
       vp.push_back(make_pair(countDivisors(i),i));
    }
    sort(vp.begin(),vp.end());
    stack<ll>stck;
    map<ll,ll>mp;
    ll index=1;
    for(ll i=0;i<1000;)
    {
       bool ok=false;
       ll tam=vp[i].first;
       while(tam==vp[i].first)
       {
           stck.push(vp[i].second);
           i++;
       }
       while(!stck.empty())
       {
           //cout<<stck.top()<<endl;
           mp[index++]=stck.top();
           stck.pop();
       }
    }
    ll t;
    cin>>t;
    ll Case=0;
    while(t--)
    {
        ll n;
        cin>>n;
        printf("Case %lld: %lld\n",++Case,mp[n]);
    }
    return 0;
}
