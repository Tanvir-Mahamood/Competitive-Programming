//https://www.spoj.com/problems/BUGLIFE/
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

void solve(int t)
{
    int no_Node, no_Edge, i, a, b;
    bool res, flag = true;

    cin >> no_Node >> no_Edge;

    for(i=1; i<=no_Node; i++) ar[i].clear(), vis[i] = 0;

    while(no_Edge--)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    for(i=1; i<=no_Node; i++)
    {
        if(vis[i] == 0)
        {
            res = dfs(i, 0);

            if(res == false) flag = false;
        }
    }
    cout << "Scenario #" << t << ":\n";
    if(flag == true) cout<<"No suspicious bugs found!\n";
    else            cout<<"Suspicious bugs found!\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    for(int i=1; i<=t; i++) solve(i);

    return 0;
}

