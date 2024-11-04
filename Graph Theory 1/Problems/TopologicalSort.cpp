#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000001];
vector<int> res;
int in[1000001];

void kahn(int n)
{
    int i;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(i=1;i<=n;i++)
    {
        if(in[i]==0) pq.push(i);
    }
    while(!pq.empty())
    {
        int curr=pq.top();
        res.push_back(curr);
        pq.pop();
        for(int child : ar[curr])
        {
            in[child]--;
            if(in[child]==0) pq.push(child);
        }
    }
    if(res.size()==n) for(int node: res) cout<<node<<" ";
    else cout<<"Sandro fails.";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        ar[x].push_back(y);
        in[y]++;
    }
    kahn(n);
    return 0;
}

