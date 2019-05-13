#include<bits/stdc++.h>
#include<stdio.h>
#define pii pair<int,int>
#define Maximum_size 22
using namespace std;
int aa=0,bb=0,cc=0;
int w,h;
char graph[Maximum_size][Maximum_size];
char grapha[Maximum_size][Maximum_size];
char graphb[Maximum_size][Maximum_size];
char graphc[Maximum_size][Maximum_size];
int s1[Maximum_size][Maximum_size],s2[Maximum_size][Maximum_size],s3[Maximum_size][Maximum_size];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void bfsa(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    grapha[x][y]='#';
    while(!q.empty())
    {
        pii top=q.front();
        for(int i=0;i<4;i++)
        {
            int f=top.first+fx[i];
            int s=top.second+fy[i];
            if(f>=0 && f<h && s>=0 && s<w && (grapha[f][s]=='.' || grapha[f][s]=='b' || grapha[f][s]=='c'))
            {   s1[f][s]=s1[top.first][top.second]+1;
                grapha[f][s]='#';
                q.push(pii(f,s));
            }
            else if(f>=0 && f<h && s>=0 && s<w &&grapha[f][s]=='h')
            {
               s1[f][s]=s1[top.first][top.second]+1;
               return;
            }
        }

        q.pop();
    }
}
void bfsb(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    graphb[x][y]='#';
    while(!q.empty())
    {
        pii top=q.front();
        for(int i=0;i<4;i++)
        {
            int f=top.first+fx[i];
            int s=top.second+fy[i];
            if(f>=0 && f<h && s>=0 && s<w && (graphb[f][s]=='.' || graphb[f][s]=='a' || graphb[f][s]=='c'))
            {
               s2[f][s]=s2[top.first][top.second]+1;
                graphb[f][s]='#';
                q.push(pii(f,s));
            }
            else if(f>=0 && f<h && s>=0 && s<w &&graphb[f][s]=='h')
            {
               s2[f][s]=s2[top.first][top.second]+1;
               return;
            }
        }
        q.pop();
    }
}
void bfsc(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    graphc[x][y]='#';
    while(!q.empty())
    {
        pii top=q.front();
        for(int i=0;i<4;i++)
        {
            int f=top.first+fx[i];
            int s=top.second+fy[i];
            if(f>=0 && f<h && s>=0 && s<w && (graphc[f][s]=='.' || graphc[f][s]=='b' || graphc[f][s]=='a'))
            {
               s3[f][s]=s3[top.first][top.second]+1;
                graphc[f][s]='#';
                q.push(pii(f,s));
            }
            else if(f>=0 && f<h && s>=0 && s<w &&grapha[f][s]=='h')
            {
               s3[f][s]=s3[top.first][top.second]+1;
               return;
            }
        }
        q.pop();
    }
}
int main()
{
    //freopen("input.txt","rt",stdin);
    int T,Case=0;
    scanf("%d",&T);
    while(T--)
    {
       int xa,ya,xb,yb,xc,yc,xh,yh;
        scanf("%d %d",&h,&w);
        getchar();
        for(int i=0;i<h;i++)
        {
            scanf("%s",graph[i]);
        }
        for(int i=0;i<h;i++)
        {
             for(int j=0;j<w;j++)
             {
                s1[i][j]=s2[i][j]=s3[i][j]=0;
                   grapha[i][j]=graph[i][j];
                   graphb[i][j]=graph[i][j];
                   graphc[i][j]=graph[i][j];
                  if(graph[i][j]=='a')
                  {
                       xa=i;
                       ya=j;
                  }
                  else if(graph[i][j]=='b')
                  {
                     xb=i;
                     yb=j;
                  }
                  else if(graph[i][j]=='c')
                  {
                     xc=i;
                     yc=j;
                  }
                  else if(graph[i][j]=='h')
                  {
                     xh=i;
                     yh=j;
                  }

             }
        }
        bfsa(xa,ya);
        bfsb(xb,yb);
        bfsc(xc,yc);
       // printf("%d %d\n",xh,yh);
        /*printf("%d %d %d \n",xa,ya,s1[xh][yh]);
         printf("%d %d %d \n",xb,yb,s2[xh][yh]);
          printf("%d %d %d \n",xc,yc,s3[xh][yh]);*/
        printf("Case %d: %d\n",++Case,max(s1[xh][yh],max(s2[xh][yh],s3[xh][yh])));
    }
    return 0;
}

