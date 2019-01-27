#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;
#define ll long long int
int main()
{
    int T,Case=0;
    scanf("%d",&T);
    int row,column;
    while(T--)
    {
        scanf("%d %d",&row,&column);
        ll sum=row*column;
        if(row==1)printf("Case %d: %d\n",++Case,column);
        else if(column==1)printf("Case %d: %d\n",++Case,row);
        else if(row==2){
            if(column%4==0)
            {
                printf("Case %d: %d\n",++Case,column);
            }
            else
            {
                if(column%4==1)printf("Case %d: %d\n",++Case,column+1);
                else printf("Case %d: %d\n",++Case,((column/4)+1)*4);
            }
        }
        else if(column==2)
        {
               if(row%4==0)
            {
                printf("Case %d: %d\n",++Case,row);
            }
            else
            {
                if(row%4==1)printf("Case %d: %d\n",++Case,row+1);
                else printf("Case %d: %d\n",++Case,((row/4)+1)*4);
            }
        }
        else if(sum%2==0)printf("Case %d: %lld\n",++Case,sum/2);
        else printf("Case %d: %lld\n",++Case,(sum/2)+1);
    }
    return 0;
}
