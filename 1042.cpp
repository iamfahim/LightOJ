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
#define in(a)          scanf("%lld",&a);
#define in2(a,b)        scanf("%lld %lld",&a,&b);
#define in3(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c);
const int MOD = (int)1e9+7;
int  main()
{
    IOS
    ll t;
    in(t)
    ll Case=0;
    while(t--)
    {
        ll n;
        in(n)
        ll arr[40]={0};
        ll tam=n;
        ll sz=32;
        while(tam!=0)
        {
            arr[sz]=(tam%2);
            tam/=2;
            sz--;
        }
        /*for(ll i=32;i>0;i--){
                check
                cout<<arr[i]<<" ";
        }*/
        bool ok=true;
        bool ok2=true;
        ll ctn=0;
        ll index=0;
        for(ll i=32;i>0;i--)
        {
            if(arr[i]==1 && ok==true)
            {
                ok=false;
                ctn++;
                index=i;
            }
            else if(arr[i]==1 && ok==false)
            {
                ctn++;
                index=i;
            }
            else if(arr[i]==0 && ok==false)
            {
                break;
            }
          //  cout<<index<<endl;
        }
        //cout<<ctn<<" "<<index<<endl;
        arr[index-1]=1;
        arr[index]=0;
        ctn--;
        for(ll i=32;i!=index;i--)
        {
           if(ctn>0)
           {
              arr[i]=1;
              ctn--;
           }
           else{
            arr[i]=0;
           }

        }
        ll sum=0;
        for(ll i=32,j=0;i>0;i--,j++)
        {
           // cout<<arr[i]<<" ";
            sum+=(pow(2,j)*arr[i]);

        }
        printf("Case %lld: %lld\n",++Case,sum);
    }
    return 0;
}
