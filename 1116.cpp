#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,w,n,m,i,j,k=1,flag;
    scanf("%lld",&t);
    while(t--)
        {
           scanf("%lld",&w);
           if(w%2!=0)
           {
               printf("Case %lld: Impossible\n",k++);
           }
           else{
            m=1;
            while(w%2==0)
            {
                m*=2;
                w/=2;
            }
               printf("Case %lld: %lld %lld\n",k++,w,m);
           }
        }
    return 0;
}
