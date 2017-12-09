#include<bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
int main()
{
    int T,r1,r2,h,p,k=0;
    double v=0,r=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&r1,&r2,&h,&p);
        r=((double)p/(double)h)*((double)(r1-r2))+(double)r2;
        v=((PI*p)/3.0)*(pow(r2,2.0)+(((double)r2)*r)+pow(r,2.0));
        printf("Case %d: %.9lf\n",++k,v);

    }
    return 0;
}
