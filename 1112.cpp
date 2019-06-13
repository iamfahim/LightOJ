#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];
int tree[mx*3];
int one;
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return ;
    }
    int left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}
void updatezero(int node,int b,int e,int i,int newvalue)
{
    if(i>e|| i<b)
    {
        return ;
    }
    if(b>=i && e<=i)
    {
        one=tree[node];
        tree[node]=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    updatezero(Left,b,mid,i,newvalue);
    updatezero(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e|| i<b)
    {
        return ;
    }
    if(b>=i && e<=i)
    {
        tree[node]+=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}
int main()
{
   //freopen("input.txt","rt",stdin);
    int Case=0,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",++Case);
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                int z;
                scanf("%d",&z);
                updatezero(1,1,n,z+1,0);
                printf("%d\n",one);
                one=0;
            }
            else if(a==2)
            {
                int z,x;
                scanf("%d %d",&z,&x);
                update(1,1,n,z+1,x);
            }
            else if(a==3)
            {
                int x,y;
                scanf("%d %d",&x,&y);
                printf("%d\n",query(1,1,n,x+1,y+1));
            }
        }
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
