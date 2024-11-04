#include<bits/stdc++.h>
using namespace std;
int vis[20];
int dis[20];
vector<int> ar[20];

void dfs(int node, int d)
{
    int i;
    vis[node] = 1;
    dis[node] = d;
    for(int child : ar[node])
    {
        if(vis[child] == 0) dfs(child, dis[node]+1);
    }
}

int main()
{
    int no_Node, no_Edge, i, a, b;
    cin >> no_Node >> no_Edge;

    while(no_Edge--)  //Input
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1, 0);

    for(i=1; i<=no_Node; i++)
    {
        cout << dis[i] << " ";
    }


    return 0;
}


