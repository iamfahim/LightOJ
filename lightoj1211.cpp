#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,k=0,a,b,x[10],result;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        x[1]=x[2]=x[3]=1;
        x[4]=x[5]=x[6]=1000;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
            scanf("%d",&a);
            if(x[j]<a)
            {
                x[j]=a;
            }
            }
            for(int j=4;j<=6;j++)
            {
                scanf("%d",&b);
                if(x[j]>b)
                {
                    x[j]=b;
                }
            }

        }
        if(x[4]>x[1] && x[5]>x[2] && x[6]>x[3])
        {
            result=(x[4]-x[1])*(x[5]-x[2])*(x[6]-x[3]);
            printf("Case %d: %d\n",++k,result);
        }
        else
        {
            printf("Case %d: 0\n",++k);
        }
    }
    return 0;
}
