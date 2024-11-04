#include <bits/stdc++.h>
using namespace std;

//Diameter of a tree
//Using SSSP
//2 times DFS Approach

int vis[10000001];
//int dis[20];
vector<int> ar[20];
int maxD,maxNode;

void dfs(int node,int d)
{
    int i;
    vis[node]=1;

    if(d>maxD)
    {
        maxD=d;
        maxNode=node;
    }
    //dis[node]=d;
    for(int child : ar[node])
    {
        if(vis[child]==0) dfs(child,d+1);
    }
}

int main()
{
    int no_Node,no_Edge,i,a,b;
    cin>>no_Node>>no_Edge;

    while(no_Edge--)  //Input
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    maxD=-1;
    dfs(1,0);

    for(i=0;i<=no_Node;i++) vis[i]=0;
    maxD=-1;
    dfs(maxNode,0);

    cout<<maxD<<"\n";

    return 0;
}





