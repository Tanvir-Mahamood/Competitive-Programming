#include<bits/stdc++.h>
using namespace std;
int vis[20];
vector<int> ar[20];

//True = Cycle found
//False = Cycle not found

bool dfs(int node, int par) //par=parent
{
    vis[node] = 1;
    for(int child : ar[node])
    {
        if(vis[child] == 0)
        {
            if(dfs(child, node)==true) return true;
        }
        else
        {
            if(child != par) return true;
        }
    }
    return false;
}

int main()
{
    int no_Node, no_Edge, i, a, b;
    cin >> no_Node >> no_Edge;

    while(no_Edge--)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    bool res = dfs(1, -1); //Node 1 and Its Parent -1

    if(res == true) cout << "Cycle found\n";
    else            cout << "Cycle not found\n";

    return 0;
}


