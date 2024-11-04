#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
//Single Source Shortest Distance

//vector<pair<int,int>> adj[3005];

map<int, int>::iterator it;

void insertEdge(map<int,int>& map, int vertex, int weight)
{
    // Check if edge already exists
    if(map.count(vertex) == 1)
    {
        // If it does, only insert a new edge it if it's weight is less than the existing edge
        if(weight < map[vertex])
        {
            map[vertex] = weight;
        }
    }
    else
    {
        map.insert(pair<int, int>(vertex, weight));
    }
}

void solve()
{
    int n,m,a,b,w,sour;
    cin>>n>>m;

    vector<map<int,int>> adj;
    adj.resize(n+1);

    while(m--)
    {
        cin>>a>>b>>w;
        insertEdge(adj[a], b, w);
        insertEdge(adj[b], a, w);
    }
    //cin >> sour;
    sour = 1;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


    vector<int> dist(n+1,INF);
    pq.push({0,sour}); //Source distance and node
    dist[sour]=0;

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

    for(int i = 1; i <= n; i++)
    {
        if(dist[i]!=0)
        {
            if(dist[i] == INF)
            {
                cout<<"-1 ";
            }
            else
            {
                cout<<dist[i]<<" ";
            }
        }
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    //cin>>t; while(t--)
        solve();

    return 0;
}





