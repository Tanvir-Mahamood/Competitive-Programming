//https://www.spoj.com/problems/BUGLIFE/
//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;

//int vis[10000001];
//int col[10000001];
//vector<int> ar[20];
vector<int> vis;
vector<int> col;



bool dfs(int node,int c,vector<int> ar[])
{
    vis[node]=1;
    col[node]=c;

    for(int child : ar[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,c^1,ar) == false) return false;
        }
        else
        {
            if(col[node]==col[child]) return false;
        }
    }
    return true;
}


void solve(int t)
{
    int no_Node,no_Edge,i,a,b;
    bool res;

    vector<int> ar[20];

    cin>>no_Node>>no_Edge;

    while(no_Edge--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    cout<<"Scenario #"<<t<<":\n";
    for(i=1;i<no_Node;i++)
    {
        res=dfs(1,0,ar);
        if(res==false)
        {
            cout<<"Suspicious bugs found!\n";
            //ar.clear();
            vis.clear();
            col.clear();
            return;
        }
    }
    cout<<"No suspicious bugs found!\n";
    //ar.clear();
    vis.clear();
    col.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t;
    for(int i=1;i<=t;i++)
    solve(i);

    return 0;
}


