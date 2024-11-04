//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i,j,op1,op2;
    char ch;
    cin>>n;
    int grid[n+1][n+1];
    int dp[n+1][n+1];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='.') grid[i][j]=0; //Free
            else grid[i][j]=1; //Obstacle
        }
    }

    for(i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            if(i==n && j==n) dp[i][j]=1;

            else
            {
                op1 = (j==n) ? 0 : dp[i][j+1]; //Turn Right
                op2 = (i==n) ? 0 :dp[i+1][j]; //Turn Down
                //dp[i][j]=(op1+op2);
                dp[i][j]=(op1+op2)%mod;

                if(grid[i][j]==1) dp[i][j]=0;
            }
        }
    }
    if(grid[n][n]==1) cout<<"0\n";
    else cout<<dp[1][1]<<nn;

    //Here dp[i][j]= total number of ways to reach (n,n) from (i,j).

    return 0;
}



/*In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i,j,op1,op2,val;
    char ch;
    cin>>n;
    int grid[n+1][n+1];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='*') grid[i][j]=-1; //Obstacle
            else grid[i][j]=0;
        }
    }

    if(grid[n][n]==-1)
    {
        cout<<"0\n";
        return 0;
    }

    for(i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            if(i==n && j==n) grid[i][j]=1;
            else if(grid[i][j]<0) grid[i][j]=0;
            else
            {

                op1 = (j==n) ? 0 : grid[i][j+1]; //Turn Right
                op2 = (i==n) ? 0 : grid[i+1][j]; //Turn Down
                val=(op1+op2)%mod;

                grid[i][j]=val;
            }
        }
    }

    cout<<grid[1][1]<<nn;

    return 0;
}

*/


