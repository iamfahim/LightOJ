//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int  main()
{
    //IOS
   //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    scanf("%d",&t);
    int Case=0;
    while(t--)
    {
        int n,m;
        list<int>mylist;
        int ctn=0;
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",++Case);
        for(int i=1; i<=m; i++)
        {
           // char  s[10];
           string s;
            int x;
            //scanf(" %s",s);
           cin>>s;
          // cout<<s<<endl;
            if(s=="pushLeft")
            {
                scanf("%d",&x);
                if(ctn==n)
                {
                    printf("The queue is full\n");

                }
                else
                {
                    printf("Pushed in left: %d\n",x);
                    mylist.push_front(x);
                    ctn++;
                }
            }
            else if(s=="pushRight")
            {
                scanf("%d",&x);
                if(ctn==n)
                {
                    printf("The queue is full\n");

                }
                else
                {
                    printf("Pushed in right: %d\n",x);
                    mylist.push_back(x);
                    ctn++;
                }
            }
            else if(s=="popLeft")
            {
                if(mylist.empty())
                {
                    printf("The queue is empty\n");

                }
                else
                {
                    int y=mylist.front();
                    mylist.pop_front();
                    printf("Popped from left: %d\n",y);
                    ctn--;
                }
            }
            else if(s=="popRight")
            {
                 if(mylist.empty())
                {

                    printf("The queue is empty\n");
                }
                else
                {
                    int y=mylist.back();
                    mylist.pop_back();
                    printf("Popped from right: %d\n",y);
                    ctn--;
                }
            }


        }



    }
    return 0;
}
