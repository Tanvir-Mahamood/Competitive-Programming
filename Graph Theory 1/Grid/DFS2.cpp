#include<bits/stdc++.h>
using namespace std;

int n,m;
bool vis[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m) return false;
    else if(vis[x][y]==true) return false;

    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<"\n";

    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i])) dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    cin>>n>>m;
    dfs(1,1);
    return 0;
}

