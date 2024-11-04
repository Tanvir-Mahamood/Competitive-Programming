#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
//Single Source Shortest Distance

vector<pair<int,int>> adj[1001];

int main()
{
    int n,m,a,b,w;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(n+1,INF);
    pq.push({0,1}); //Source distance and node
    dist[1]=0;

    while(!pq.empty())
    {
        int curr=pq.top().second; //smallest value
        int curr_d=pq.top().first;
        pq.pop();

        for(pair<int,int> edge: adj[curr])
        {
            if(curr_d+edge.second<dist[edge.first])
            {
                dist[edge.first]=curr_d+edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}
