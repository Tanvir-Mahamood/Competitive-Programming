//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"


int getBestCandidates(map<int,int>& candidates,int v)
{
    auto it=candidates.lower_bound(v);
    if(it==candidates.begin()) return 0;
    it--;
    return it->second;
}

void insert(map<int,int>& candidates,int v,int adv)
{
    if(candidates[v]>=adv) return;
    candidates[v]=adv;
    auto it=candidates.find(v);
    it++;
    while(it != candidates.end() && it->second<=adv)
    {
        auto temp=it;
        it++;
        candidates.erase(temp);
    }
}

int solve(vector<int>& v,int n)
{
    int dp[n];
    map<int,int> candidates;

    dp[0]=1;
    candidates[v[0]]=dp[0];

    for(int i=1; i<n; i++)
    {
        dp[i]=1+getBestCandidates(candidates,v[i]);
        insert(candidates,v[i],dp[i]);
    }
    return *max_element(dp,dp+n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n)<<nn;

    return 0;
}



