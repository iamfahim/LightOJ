#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,a[60],prev,Size,k=0;
    scanf("%d",&T);
    while(T--)
    {
        Size=0;
        int Count=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                prev=2;
                Size=a[i];
                Count+=ceil(abs(Size-prev)/5.0);
            }

            else {
                    prev=a[i-1];
                    Size=a[i];
               Count+=ceil(abs(Size-prev)/5.0);
            }

        }
        printf("Case %d: %d\n",++k,Count);
    }
    return 0;
}
