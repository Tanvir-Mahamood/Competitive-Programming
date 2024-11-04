#include<bits/stdc++.h>
using namespace std;
int vis[20];
int In[20];  //Array of In-Time for Nodes
int Out[20]; //Array of Out-Time for Nodes
int timer=1;
vector<int> ar[20];

bool dfs(int v)
{
    vis[v] = 1;
    In[v] = timer++;
    for(int child : ar[v])
    {
        if(vis[child] == 0) dfs(child);
    }
    Out[v] = timer++;
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

    dfs(1);

    cout << "In time: ";
    for(int i=1; i<=no_Node; i++) cout << In[i] << " ";
    cout << "\nOut time: ";
    for(int i=1; i<=no_Node; i++) cout << Out[i] << " ";


    return 0;
}


