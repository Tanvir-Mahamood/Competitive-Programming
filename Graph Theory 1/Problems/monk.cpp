//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;
int no_Node;
int vis[10001];
int dist[10001];
vector<int> ar[10001];

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


void solve()
{
    int no_Edge,i,a,b;
    cin>>no_Node>>no_Edge;

    for(i=0;i<=no_Node;i++)  //clear
    {
        ar[i].clear();
        vis[i]=0;
        dist[i]=0;
    }

    while(no_Edge--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    bfs(1);

    cout<<dist[no_Node]<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}


