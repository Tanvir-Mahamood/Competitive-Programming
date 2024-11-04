//https://www.spoj.com/problems/NAKANJ/cstart=30
#include<bits/stdc++.h>
using namespace std;

int n=8;
int m=8;
int dist[10][10];
int vis[10][10];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m) return false;
    else if(vis[x][y]==1) return false;

    return true;
}

int dx[]= {-2,-1,1,2,2,1,-1,-2};
int dy[]= {1,2,2,1,-1,-2,-2,-1};


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

        for(int i=0; i<8; i++)
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

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dist[i][j]=0;
                vis[i][j]=0;
            }
        }

        int x,y,x1,y1;

        x=str1[0]-'a'+1;
        y=str1[1]-'0';

        x1=str2[0]-'a'+1;
        y1=str2[1]-'0';

        bfs(x,y);
        cout<<dist[x1][y1]<<"\n";
    }

}



