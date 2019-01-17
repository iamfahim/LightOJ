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
int  main()
{
    IOS
    ll t;
    cin>>t;
    ll Case=0;
    while(t--)
    {
        ll m;
        string a,b;
        vector<pair<string,string> >vs;
        map<pair<string,string>,ll>mymap;
        cin>>m;
        for(ll i=1;i<=m;i++)
        {
            cin>>a>>b;
            vs.pb(mk(a,b));
            mymap[{a,b}]=1;
        }
        bool ok=false;
        for(ll i=0;i<m;i++)
        {
           string x,y;
           x=vs[i].ff;
           y=vs[i].ss;
           if(mymap[{y,x}]==1){
            ok=true;
            break;
           }
        }
        if(ok)cout<<"Case "<<++Case<<": No"<<endl;
        else cout<<"Case "<<++Case<<": Yes"<<endl;

    }
    return 0;
}
