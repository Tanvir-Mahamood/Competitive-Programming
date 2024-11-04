//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;

vector<int> ar[1000001];
int vis[1000001];
int cc[1000001];
int curr_cc;

void dfs(int node)
{
    vis[node]=1;
    cc[node]=curr_cc;
    //cout<<node<<" "<<curr_cc<<" ";
    for(int child : ar[node])
    {
        if(vis[child==0]) dfs(child);
    }
}

void solve()
{
    int n,m,a,b;
    string op;
    cin>>n>>m;

    for(int i=0;i<=n;i++) //clear
    {
        ar[i].clear();
        vis[i]=0;
        cc[i]=0;
    }
    curr_cc=0;
    vector<pair<int,int>> edgeList;
    while(m--)
    {
        cin>>a>>op>>b;
        if(op=="=")
        {
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        else
        {
            edgeList.push_back({a,b});
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0) //not visited
        {
            //cout<<i<<nn;
            curr_cc++;
            dfs(i);
        }
    }

    bool flag=true;
    for(int i=0;i<edgeList.size();i++)
    {
        a=edgeList[i].first;
        b=edgeList[i].second;
        //cout<<cc[a]<<" "<<cc[b]<<nn;
        if(cc[a]==cc[b])
        {
            flag=false;
            break;
        }
    }
    //if(flag==true) yes;
    //else no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}


