#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462


bool isSafe(int row, int col, vector<vector<char>>& board, char ch)
{
    for(int i=0; i<9; i++)
    {
        if(board[row][i] == ch) return false;
        if(board[i][col] == ch) return false;
        if(board[ 3*(row/3) + i/3 ][ 3*(col/3) + i%3 ] == ch) return false;
    }
    return true;
}

void solve(int i, int j, vector<vector<char>>& board, bool &isFinished)
{
    if(i == 9)
    {
        isFinished = true;
        return;
    }

    if(board[i][j] != '.') // if its a character, then propagate for next.
    {
        if(j == 8) solve(i+1, 0, board, isFinished);
        else solve(i, j+1, board, isFinished);
    }
    else // its a blank cell. Put chracters & try to solve entire board.
    {
        for(char ch='9'; ch>='1'; ch--)
        {
            if(isSafe(i, j, board, ch))
            {
                board[i][j] = ch; // let place a character

                if(j == 8) solve(i+1, 0, board, isFinished); // propagate for next
                else solve(i, j+1, board, isFinished);

                if(isFinished) return;
                board[i][j] = '.'; //present character fails to solve. Lets try for new one
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    bool flag = false;
    solve(0, 0, board, flag);
}

int main()
{
//    fastio;
//    int t = 1;
//    cin >> t;
//    for(int i=1;i<=t;i++)
//    {
//        //cout << "Case " << i << ": \n";
//        solve();
//    }

    vector<vector<char>> board(9,vector<char>(9));
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << nn;
    }
    cout << nn;

    return 0;
}

/*
Sample Input:

5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Sample Output:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

Sudoku solver in leatcode.
Thanks a random coder to make me able to solve this.
*/



