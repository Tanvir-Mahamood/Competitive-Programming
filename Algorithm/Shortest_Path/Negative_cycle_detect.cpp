#include<bits/stdc++.h>
using namespace std;
#define nn '\n'

bool using_bellman_ford()
{
    int n, m, i, j;
    cin >> n >> m;

    struct edge
    {
        int a, b, c;
    };
    int dist[n+1];
    for(i=1; i<=n; i++) dist[i] = 1e9+7;

    edge ed[m];
    for(i=0; i<m; i++) cin >> ed[i].a >> ed[i].b >> ed[i].c;

    dist[1] = 0;
    int cnt = 0;
    for(i=0; i<n; i++)
    {
        bool f = 0;
        for(j=0; j<m; j++)
        {
            if(dist[ed[j].a] + ed[j].c < dist[ed[j].b])
            {
                dist[ed[j].b] = dist[ed[j].a] + ed[j].c;
                f = 1;
            }
        }
        if(f) cnt++;
    }

    return cnt==n;
}

signed main()
{
    int check = using_bellman_ford();
    if(check) cout << "negative cycle found\n" << nn;
    else cout << "no_negative_cycle\n" <<nn;

}
