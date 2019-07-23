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
#define mx 100001
ll arr[mx];
struct info {
    ll prop, sum;
}tree[mx * 3];
void init(ll node, ll b, ll e)
{
    if(b==e){
        tree[node].sum = arr[b];
        return ;
    }
    ll left = 2*node;
    ll right = 2*node + 1;
    ll mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1,e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
//sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ
void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    ll Left = node * 2;
    ll Right = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}
ll query(ll node, ll b, ll e, ll i, ll j, ll carry)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
int  main()
{
    IOS
    ll t;
    scanf("%lld",&t);
    ll Case=0;
    while(t--)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(ll i=1;i<=n;i++)
        {
            arr[i]=0;
        }
        init(1, 1, n);
        printf("Case %lld:\n",++Case);
        for(ll i=1;i<=q;i++)
        {
            ll chk,x,y,v;
            scanf("%lld",&chk);
            if(!chk)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1, 1, n,x+1,y+1,v);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                ll val=query(1,1,n,x+1,y+1,0);
                printf("%lld\n",val);
            }
        }
        ms(tree,0);
    }
    return 0;
}
