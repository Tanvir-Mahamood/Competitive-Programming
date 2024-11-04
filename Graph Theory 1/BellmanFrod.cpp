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

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) //phase
    {
        for (Edge edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if(distance[i] == INT_MAX) cout << " INF ";
        else cout << distance[i] << " ";
    }
    cout << nn;
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

