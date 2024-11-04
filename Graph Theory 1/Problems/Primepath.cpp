//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;

vector<int> ar[100001];
vector<int> primes; //it will contain all 4 digits prime numbers
int vis[100001],dist[100001];

bool isPrime(int n)
{
    for(int i=0;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

bool isValid(int a,int b)
{
    int cnt=0;
    while(a>0)
    {
        if(a%10 != b%10) cnt++;

        a/=10;
        b/=10;
    }
    if(cnt==1) return true;
    else return false;
}

void buildGraph()
{
    int i,j;
    for(i=1000;i<=9999;i++)
    {
        if(isPrime(i)) primes.push_back(i);
    }
    for(i=0;i<primes.size();i++)
    {
        for(j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];

            if(isValid(a,b))
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
        }
    }
    //cout<<"Done\n";
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;

    while(!q.empty())
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
    int a,b,i;
    cin>>a>>b;
    for(i=1000;i<=9999;i++) //clear
    {
        //ar[i].clear;
        dist[i]=-1;
        vis[i]=0;
    }

    bfs(a);

    if(dist[b]==-1) cout<<"Impossible\n";
    else cout<<dist[b]<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    buildGraph();
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}


