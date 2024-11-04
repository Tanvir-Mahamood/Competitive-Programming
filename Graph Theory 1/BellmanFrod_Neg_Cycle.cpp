#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

struct Edge
{
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int E, int source)
{
    vector<int> distance(V+1, INT_MAX);
    distance[source] = 0;
    int cnt = 0;

    for (int i = 0; i < V; i++) //phase
    {
        bool flag = 0;
        for (Edge edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                flag = 1;
            }
        }
        if(flag) cnt++;
    }

    if(cnt == V) cout << "Negative Cycle Found\n";
    else cout << " No negative cycle found\n";
}

int main()
{
    int V, E, i, a, b, w;
    cin >> V >> E;
    vector<Edge> edges;
    for(i=0; i<E; i++)
    {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    int sourceVertex = 1; //u may adjust
    bellmanFord(edges, V, E, sourceVertex);

    return 0;
}


