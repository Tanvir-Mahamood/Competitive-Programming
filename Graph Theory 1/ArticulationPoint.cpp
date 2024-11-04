#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

vector<int> graph[MAXN];
bool visited[MAXN];
int parent[MAXN];
int low[MAXN];
int disc[MAXN];
bool ap[MAXN];
int timeCount;

void APUtil(int u)
{
    visited[u] = true;
    disc[u] = low[u] = ++timeCount;
    int children = 0;
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
            {
                ap[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                ap[u] = true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findAP(int n)
{
    memset(visited, false, sizeof visited);
    memset(ap, false, sizeof ap);
    memset(parent, -1, sizeof parent);
    timeCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            APUtil(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ap[i])
        {
            cout << i << " is an articulation point\n";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    findAP(n);
    return 0;
}

