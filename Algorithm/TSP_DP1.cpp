//Traveling Salesman Problem
//Using DP
//Hamiltonian Path
//O(2^n * n)

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

const int MAX_N = 15; //maximum number of cities
int n; //number of cities
int dist[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int tsp(int mask, int pos)
{
    if(mask == (1 << n) - 1) return dist[pos][0];

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;

    for(int city=0; city<n; city++) //Try to go to all unvisited cities
    {
        if((mask & (1 << city)) == 0) //if the city is unvisited
        {
            int new_mask = mask | (1 << city);
            int newAns = dist[pos][city] + tsp(mask | new_mask, city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    // Initialize the dp table
    for (int i = 0; i < (1 << MAX_N); i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            dp[i][j] = -1;
        }
    }

    int starting_city = 0;
    int mask = (1 << starting_city);
    int min_cost = tsp(mask, starting_city);

    cout << min_cost << nn;

    return 0;
}




