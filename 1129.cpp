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
ll ch[200005][10];
struct compare
{
    bool operator()(const std::string& first, const std::string& second)
    {
        return first.size() > second.size();
    }
};
int  main()
{
    IOS
    ll t,n;
    ll Case=0;
    cin>>t;
    memset(ch,0,sizeof(ch));
    while(t--)
    {
        ll ss=0;
        bool ok=false;
        cin>>n;
        vector<string>Vs;
        string s;
        for(ll i=0; i<n; i++)
        {
            cin>>s;
            Vs.push_back(s);
        }
        compare c;
        sort(Vs.begin(),Vs.end(),c);
        for(ll i=0; i<n; i++)
        {
            string tam=Vs[i];
            ll u=0;
            ll sz=tam.size();
            for(ll i=0; i<sz; i++)
            {
                ll c=tam[i]-48;
                if(ok==true)
                   {
                    break;
                   }
                if(i==sz-1 && ch[u][c]!=0 && ok==false)
                {
                    ok=true;
                }
                if(ch[u][c]==0)
                {
                    ch[u][c]=++ss;
                }
                u=ch[u][c];
            }
        }
        if(ok)
        {
            cout<<"Case "<<++Case<<": NO"<<endl;
        }
        else
        {
            cout<<"Case "<<++Case<<": YES"<<endl;
        }
        memset(ch,0,sizeof(ch));
    }
    return 0;
}
