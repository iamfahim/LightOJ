#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,s,l,i,j=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&s);
        l=ceil(sqrt(s));
        n=l*l-l+1;
        if(l%2==1)
        {
            if(s<n)
            {
                printf("Case %lld: %lld %lld\n",j++,l,l-n+s);
            }
            else
            {
                printf("Case %lld: %lld %lld\n",j++,l+n-s,l);
            }
        }
        else
        {
            if(s<n)
            {
                printf("Case %lld: %lld %lld\n",j++,l-n+s,l);
            }
            else
            {
                printf("Case %lld: %lld %lld\n",j++,l,l-s+n);
            }
        }
    }
    return 0;
}
