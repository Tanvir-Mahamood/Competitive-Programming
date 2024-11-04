#include<bits/stdc++.h>
using namespace std;

int n,m;
int ar[1001][1001];
int vis[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m) return false;
    else if(vis[x][y]==1 || ar[x][y]==0) return false;

    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;

    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i])) dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    int i,j,cnt=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>ar[i][j];
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(vis[i][j]==0 && ar[i][j]==1)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<"\n";
    return 0;
}

/*
6 6
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1
*/
