#include<bits/stdc++.h>
using namespace std;
int vis[1001];
vector<int> ar[1001];

void dfs(int v)
{
    int i, child;
    vis[v] = 1;
    //cout<<v<<"->";
    for(i=0; i<ar[v].size(); i++)
    {
        child = ar[v][i];
        if(vis[child] == 0) dfs(child);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int no_Node, no_Edge, i, a, b, cnt = 0;
    cin >> no_Node >> no_Edge;

    while(no_Edge--)  //Input
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    for(i=1; i<=no_Node; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}


