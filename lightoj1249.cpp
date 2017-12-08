#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,k=0;
    char s[25];
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,v;
        vector<pair<int,string> >v1;
        scanf("%d",&n);
        getchar();

        for(int i=0;i<n;i++)
        {
            scanf("%s %d %d %d",s,&a,&b,&c);
            v=a*b*c;
            v1.push_back(make_pair(v,s));
        }
        int Max=0,Min=999999,mx,mn;
      for(int i=0;i<v1.size();i++){
        if(v1[i].first>Max)
        {
            Max=v1[i].first;
            mx=i;
        }
        if(v1[i].first<Min)
        {
            Min=v1[i].first;
            mn=i;
        }
      }
      if(Max!=Min)
      {
          cout<<"Case "<<++k<<": "<<v1[mx].second<<" took chocolate from "<<v1[mn].second<<endl;
      }
      else{
        printf("Case %d: no thief\n",++k);
      }

    }
    return 0;
}
