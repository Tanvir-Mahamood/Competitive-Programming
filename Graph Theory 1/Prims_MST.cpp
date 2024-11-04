//Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

const ll N = 1e5 + 3;
vector<vector<ll>> adj[N];
ll cost = 0;
#define INF  1e9;
vector<ll> dist(N), parent(N);
vector<bool> vis(N);

void primsMST(ll source, ll n) // 0 based calculation
{
    for(ll i=0; i<=n; i++)
    {
        dist[i] = INF;
    }
    set<vector<ll>> s;
    dist[source] = 0;
    s.insert({0, source});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        ll u = x[1];
        ll v = parent[x[1]];
        ll w = x[0];
        cout << u << " " << v << " " << w << nn;
        cost += w;
        for(auto it: adj[x[1]])
        {
            if(vis[it[0]]) continue;
            if(dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

void solve()
{
    ll no_Node, no_Edge, i, u, v, w, source;
    cin >> no_Node >> no_Edge;
    for(i=0; i<no_Edge; i++)
    {
        cin >> u >> v >> w; //1 based input
        u--, v--; //0 based input
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> source;
    primsMST(source-1, no_Node);
    cout << cost << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}

/*
4 5
1 2 1
3 2 150
4 3 99
1 4 100
3 1 200
4
*/
