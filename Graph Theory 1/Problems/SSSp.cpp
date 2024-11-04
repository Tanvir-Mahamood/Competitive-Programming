//https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/
//In the name of Allah, the Gracious, the Merciful
#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int dis[1001];
vector<int> ar[1001];
int minn=100000;

void dfs(int node,int d)
{
    int i;
    vis[node]=1;
    dis[node]=d;
    for(int child : ar[node])
    {
        if(vis[child]==0) dfs(child,dis[node]+1);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int no_Node,no_Edge,i,a,b,q,girl,res;
    cin>>no_Edge;
    no_Edge--;

    while(no_Edge--)  //Input
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1,0);

    cin>>q;
    while(q--)
    {
        cin>>girl;
        if(dis[girl]<minn)
        {
            minn=dis[girl];
            res=girl;
        }
        if(minn==dis[girl] && girl<res)  res=girl;
    }
    cout<<res<<"\n";


    return 0;
}





