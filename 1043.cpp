//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define ull            unsigned long long
#define min3(a,b,c)    min(a,min(b,c))
#define min4(a,b,c,d)  min(a,min(b,min(c,d)))
#define max3(a,b,c)    max(a,max(b,c))
#define max4(a,b,c,d)  max(a,max(b,max(c,d)))
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int  main()
{
    IOS
    ll t;
    cin>>t;
    ll Case=0;
    while(t--)
    {
        double ab,ac,bc,rrt;
        cin>>ab>>ac>>bc>>rrt;
        double ad,ae,de,aabc,aade,abcde,s2;
        double s1=(ab+ac+bc)/2;
        aabc=sqrt(s1*(s1-ab)*(s1-ac)*(s1-bc));
        double rrrt;
        bool ok=true;
        double low=0.0;
        double high=ab;
        double mid;
        while(ok)
        {
            mid=(high+low)/2;
            ad=mid;
            ae=(ad/ab)*ac;
            de=bc*(ad/ab);
            s2=(ad+ae+de)/2;
            aade=sqrt(s2*(s2-ad)*(s2-ae)*(s2-de));
            abcde=aabc-aade;
            rrrt=(aade/abcde);
            if(abs(rrrt-rrt)<.000000001)
            {
                ok=false;
            }
            else if(rrrt<rrt)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        printf("Case %lld: %.10lf\n",++Case,ad);
    }
    return 0;
}
