#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;
#define Max_size 20010
vector<int>adj[Max_size];
int color[Max_size];
int graphcoloring(int s)
{
    int countone=0,countzero=0;
    queue<int>Q;
    Q.push(s);
    color[s]=1;
    countone++;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                if(color[v]==1)
                    countone++;
                if(color[v]==0)
                    countzero++;
                Q.push(v);
            }
        }
    }
    return max(countone,countzero);
}
void CLR()
{
    for(int i=0; i<Max_size; i++)
    {
        adj[i].clear();
    }
}
int main()
{
    IOS
    int T;
    int Case=0;
    cin>>T;
    while(T--)
    {
        int x,y,E;
        set<int>st;
        cin>>E;
        for(int i=0; i<E; i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            st.insert(x);
            st.insert(y);
        }
        int ans=0;
        set<int>::iterator it;
        for (it=st.begin(); it!=st.end(); ++it)
        {
            color[*it]=-1;
        }
        for (it=st.begin(); it!=st.end(); ++it)
        {
            if(color[*it]==-1)
            {
                int fun= graphcoloring(*it);
                ans+=fun;
            }
        }
        cout<<"Case "<<++Case<<": "<<ans<<endl;
        CLR();
    }
    return 0;
}
