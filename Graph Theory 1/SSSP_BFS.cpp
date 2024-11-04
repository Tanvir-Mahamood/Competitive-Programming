#include<bits/stdc++.h>
using namespace std;
int vis[20];
int dist[20];
vector<int> ar[20];

void bfs(int src) //src=source
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;

    while(!q.empty()) //while q is not equal to empty
    {
        int curr=q.front();
        q.pop();
        for(int child: ar[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                dist[child]=dist[curr]+1;
                vis[child]=1;
            }
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

    bfs(1);

    for(i=0;i<20;i++) cout<<dist[i]<<" ";

    return 0;
}


