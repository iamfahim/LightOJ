#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,m,n,j=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&m,&n);
        if(((m*n)%2)==0)
        {
            printf("Case %d: %d\n",j++,(m*n)/2);
        }
        else
        {
            printf("Case %d: %d\n",j++,((m*n)+1)/2);
        }
    }
    return 0;
}
