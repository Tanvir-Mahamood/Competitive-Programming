#include <bits/stdc++.h>
#define ll long long
using namespace std;

int vis[10001];
vector<int> ar[10001];
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
    for(int child : ar[node])
    {
        if(vis[child]==0) dfs(child,d+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int no_Node,no_Edge,i,a,b;
    cin>>no_Node;
    no_Edge=no_Node-1;

    while(no_Edge--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    maxD=-1;
    dfs(1,0);

    for(i=0;i<no_Node;i++) vis[i]=0; //clear
    maxD=-1;
    dfs(maxNode,0);

    cout<<maxD<<"\n";

    return 0;
}





