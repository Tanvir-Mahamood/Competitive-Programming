#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    // Create a 2D vector of characters
    vector<vector<char>> grid;

    // Input the 2D vector using push_back()
    for(int i=0;i<n;i++)
    {
        vector<char> row;
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            row.push_back(c);
        }
        grid.push_back(row);
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

