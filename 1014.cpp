//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int  main()
{
    ll t;
    scanf("%lld",&t);
    ll Case=0;
    while(t--)
    {
        ll p,l;
        scanf("%lld %lld",&p,&l);
        if((p-l)<=l)
        {
            printf("Case %lld: impossible\n",++Case);
            continue;
        }
       set<ll>st;
       ll n=(p-l);
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                    if(i>l){
                st.insert(i);
                    }
            }
            else{
                    if(i>l){
                st.insert(i);
                    }
                    if(n/i>l){
                st.insert(n/i);
            }
            }
        }
    }
    printf("Case %lld:",++Case);
    for(ll num:st)
    {
        printf(" %lld",num);
    }
    printf("\n");
    }
    return 0;
}
