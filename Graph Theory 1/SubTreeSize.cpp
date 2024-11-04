#include<bits/stdc++.h>
using namespace std;

int vis[20],subsize[20];
vector<int> ar[20];

int dfs(int node)
{
    vis[node]=1;
    int curr_size=1;
    for(int child : ar[node])
    {
        if(vis[child]==0)
        {
            curr_size+=dfs(child);
        }
    }
    subsize[node]=curr_size;
    return curr_size;
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

    dfs(1);
    for(int i=1;i<=no_Node;i++) cout<<subsize[i]<<" ";

    return 0;
}


