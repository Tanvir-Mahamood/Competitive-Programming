#include<bits/stdc++.h>
#define nn '\n'
using namespace std;

void dijkstra()
{
    int n, e, i, x, y, w;
    cin >> n >> e;

    vector<pair<int, int>> graph[n+1];
    int dist[n+1];

    for(i=1; i<=n; i++) dist[i] = 1e9;

    while(e--)
    {
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        //graph[y].push_back(make_pair(x,w)); bcz directed graph
    }

    set<pair<int,int>> st;
    st.insert(make_pair(0, 1));

    dist[1] = 0;
    while(!st.empty())
    {
        pair<int, int> par = *st.begin();
        st.erase(st.begin());

        for(auto child: graph[par.second])
        {
            if(dist[child.first] > dist[par.second] + child.second )
            {
                dist[child.first] = dist[par.second] + child.second;
                st.insert(make_pair(dist[child.first], child.first));
            }
        }
    }

    for(i=1; i<=n; i++) cout << dist[i] << " ";
    cout << nn;
}

void bellman_ford()
{
    int n, e, i, j;
    cin >> n >> e;

    struct edge
    {
        int a,b,c;
    };

    int dist[n+1];
    for(i=1; i<=n; i++) dist[i] = 1e9+7;

    edge ed[e];
    for(i=0; i<e; i++) cin >> ed[i].a >> ed[i].b >> ed[i].c;

    dist[1] = 0;
    for(i=1; i<n; i++)
    {
        for(j=0; j<e; j++)
        {
            if(dist[ed[j].b] > dist[ed[j].a] + ed[j].c) dist[ed[j].b] = dist[ed[j].a] + ed[j].c;
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << " "; // it may contain 1e7, so handle it
    cout << nn;
}

int main()
{
    //dijkstra();
    bellman_ford();
}
