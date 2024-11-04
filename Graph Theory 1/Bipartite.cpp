#include<bits/stdc++.h>
using namespace std;
int vis[2001];
int col[2001]; //Color Array
vector<int> ar[2001];

bool dfs(int node,int c) //C=color
{
    vis[node] = 1;
    col[node] = c;

    for(int child : ar[node])
    {
        if(vis[child] == 0)
        {
            if(dfs(child, c^1) == false) return false; //c^1=> Inverter. if c==1 then c^1=0 , if c==0 then c^1=1
        }
        else
        {
            if(col[node] == col[child]) return false;
        }
    }
    return true;
}

int main()
{
    int no_Node, no_Edge, i, a, b;
    bool res;

    cin >> no_Node >> no_Edge;

    while(no_Edge--)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    res = dfs(1,0);
    if(res == true) cout<<"YES, Bipartite Graph\n";
    else            cout<<"No,its not Bipartite Graph\n";

    return 0;
}


