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

void dfs(int x,int y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<"\n";

    if(isValid(x-1,y)) dfs(x-1,y); //UP
    if(isValid(x,y+1)) dfs(x,y+1); //RIGHT
    if(isValid(x+1,y)) dfs(x+1,y); //DOWN
    if(isValid(x,y-1)) dfs(x,y-1); //LEFT
}

int main()
{
    cin>>n>>m;
    dfs(1,1);
    return 0;
}
