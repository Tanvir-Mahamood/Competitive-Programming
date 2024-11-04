#include<bits/stdc++.h>
using namespace std;

int vis[20];
vector<int> ar[20];
int in[20],low[20];
int timer;

void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child : ar[node])
    {
        if(child==par) continue;
        if(vis[child]==1) //Ancester found. Its Back Edge
        {
            low[node]=min(low[node],in[child]);
        }
        else //Forward
        {
            dfs(child,node);
            if(low[child]>in[node]) cout<<node<<"-"<<child<<" bridge\n";
            low[node]=min(low[node],low[child]);
        }
    }
}

int main()
{
    int no_Node,no_Edge,i,a,b;
    cin>>no_Node>>no_Edge;

    while(no_Edge--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1,-1); //node and parent


    return 0;
}


