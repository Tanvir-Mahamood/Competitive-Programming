#include<bits/stdc++.h>
using namespace std;

int n,m;
int dist[1001][1001];
int vis[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m) return false;
    else if(vis[x][y]==1) return false;

    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs(int srcX,int srcY)
{
    queue<pair<int,int>>q;
    q.push({srcX,srcY});
    vis[srcX][srcY]=1;
    dist[srcX][srcY]=0;

    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(isValid(currX+dx[i],currY+dy[i]))
            {
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                q.push({newX,newY});
                vis[newX][newY]=1;
                dist[newX][newY]=dist[currX][currY]+1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    bfs(x,y);
}
