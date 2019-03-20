//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll   long long int
ll pi[1000005];
ll ctn=0;
string P,T;
int prefixFunction()
{
    int now;
    pi[0]=now=-1;
    int len=P.size();
    for(int i=1;i<len;i++)
    {
        while(now!=-1 && P[now+1]!=P[i])
            now=pi[now];
        if(P[now+1]==P[i])pi[i]=++now;
        else pi[i]=now=-1;
    }
}
int kmp()
{
    int now;
    now=-1;
    int n=T.size();
    int m=P.size();
    for(int i=0;i<n;i++)
    {
        while(now!=-1 && P[now+1]!=T[i])
            now=pi[now];
        if(P[now+1]==T[i])++now;
        else now=-1;
        if(now==m-1)
        {
            ctn++;
            now=pi[now];
        }
    }
    return 0;
}
int  main()
{
    ll t;
    ll Case=0;
    cin>>t;
    while(t--){
    cin>>T;
    cin>>P;
      ctn=0;
      prefixFunction();
     kmp();
     printf("Case %lld: %lld\n",++Case,ctn);
     for(ll i=0;i<1000005;i++){
            pi[i]=0;
    }
   //cout<<"Case "<<++Case<<": "<<ctn<<endl;
    }
    return 0;
}


