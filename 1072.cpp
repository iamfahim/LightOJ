#include<bits/stdc++.h>
using namespace std;
int main()
{
    double R,r,pi=acos(-1);
    int T,n,r1,i=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %d",&R,&n);
        r=(R*sin(pi/n))/(1+sin(pi/n));
        r1=(R*sin(pi/n))/(1+sin(pi/n));
        if((r1-r)==0)
        {
            printf("Case %d: %.0lf\n",i++,r);
        }
        else
        {
            printf("Case %d: %.10lf\n",i++,r);
        }

    }
    return 0;
}

