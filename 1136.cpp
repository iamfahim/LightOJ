#include<bits/stdc++.h>
using namespace std;
int division(int a)
{
    if(a==0 || a==1)
    {
        return 0;
    }
    return a-1-(a-1)/3;
}
int main()
{
    int t,i=1,j,k,l,A,B;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&A,&B);
        l=division(B)-division(A-1);
        printf("Case %d: %d\n",i++,l);
    }
    return 0;
}
