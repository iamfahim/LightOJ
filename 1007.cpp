//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             unsigned long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
#define MAX 5000005
ll phi[MAX]={0};
void sievePHI(){
    ll i,j;
    for( i=2;i<MAX;i++){
        if( phi[i]==0){
            phi[i] = i-1;
            for( j = i*2; j<MAX; j+=i){
                if( phi[j] == 0 )phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1) ;
            }
        }
    }
}
void precalculation()
{
    for(ll i=2;i<MAX;i++)
    {
        phi[i]=(phi[i-1]+phi[i]*phi[i]);
    }
}
int  main()
{
    IOS
    sievePHI();
    precalculation();
    ll t,Case=0;
    scanf("%llu",&t);
    while(t--)
    {
        ll a,b;
        scanf("%llu %llu",&a,&b);
        ll sum=0;
        if(a==b)
        {
            printf("Case %llu: %llu\n",++Case,phi[a]-phi[a-1]);
            continue;
        }
        printf("Case %llu: %llu\n",++Case,phi[b]-phi[a-1]);
    }
    return 0;
}
