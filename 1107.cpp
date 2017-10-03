#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,x1,y1,x2,y2,x,y,t,i=0;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",++i);
      scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
      scanf("%d",&t);

      while(t--)
      {
          scanf("%d %d",&x,&y);
          if((x>x1 && x<x2) && (y>y1 && y<y2))
          {
              printf("Yes\n");
          }
          else
          {
              printf("No\n");
          }
      }
    }
    return 0;
}
