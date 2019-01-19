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
ll f[1000005];
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a;
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD;
 	b /= 2;
 	}
 return x;
}
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}
ll C(ll n, ll r, ll MOD)
{

 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){
    ll t,n,r;
    cin>>t;
    f[0] = 1;
    ll Case=0;
	for(int i = 1 ; i <= 1000000 ; i++)
		{f[i] = (f[i-1]*i)%1000003;}
    while(t--){
	  cin>>n>>r;
 	cout <<"Case "<<++Case<<": "<<C(n,r,1000003)<< endl;
    }
    return 0;
}
