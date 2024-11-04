#include<bits/stdc++.h>
#define nn '\n'
using namespace std;

void Dijkstra_alogrithm(vector<pair<int,int>> graph[],int n,int s, vector<vector<int>> &dist)
{
    for(int i=1; i<=n; i++) dist[s][i] = 1e9+7;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,s));
    dist[s][s] = 0;

    while(!pq.empty())
    {
        pair<int,int> par = pq.top();
        pq.pop();

        for(auto child: graph[par.second])
        {

            if(dist[s][child.first] > dist[s][par.second] + child.second)
            {
                dist[s][child.first] = dist[s][par.second] + child.second;
                pq.push(make_pair(dist[s][child.first],child.first));
            }
        }
    }
}

void using_dijkstra()
{

    int n, e, x, y, w, i, j;
    cin >> n >> e;
    vector<pair<int, int>> graph[n+1];

    while(e--)
    {
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    vector<vector<int>> dist (n+1, vector<int>(n+1));

    for(i=1; i<=n; i++)
    {
        Dijkstra_alogrithm(graph, n, i, dist);
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++) cout << dist[i][j] << " ";
        cout << nn;
    }
}

void using_floyd_warshall()
{
    int n, e, i, j;
    cin >> n >> e;

    int graph[n+1][n+1];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j) graph[i][j] = 0;
            else graph[i][j] = 1e9+7;
        }
    }

    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y] = w;
        graph[y][x] = w;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << nn;
    }
}




int main()
{
    //using_dijkstra();
    using_floyd_warshall();
}
