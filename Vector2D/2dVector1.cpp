#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    // Create a 2D vector of characters
    vector<vector<char>> grid(n,vector<char>(m));

    // Input the 2D vector
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    // Output the 2D vector
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

