//Square Root Decomposition
//Range Sum Query

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

int query(int *blocks, int * arr, int L, int R, int rn)
{
    int ans = 0;

    while(L < R && L != 0 && L % rn != 0) //Left part
    {
        ans += arr[L];
        L++;
    }

    while(L + rn <= R) //Middle part
    {
        int block_id = L / rn;
        ans += blocks[block_id];
        L += rn;
    }
    while(L <= R) //Right part
    {
        ans += arr[L];
        L++;
    }
    return ans;
}

void update(int *blocks, int *arr, int i, int val, int rn)
{
    int block_id = i / rn;
    blocks[block_id] += (val - arr[i]); //updating blocks array
    arr[i] = val;                       //updating main array
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int n, i;
    cin >> n;
    int a[n];
    for(i=0; i<n; i++) cin >> a[i];

    int rn = sqrt(n);
    int *blocks = new int[rn+1]{0};

    //build a block O(1)
    int block_id = -1;
    for(i=0; i<n; i++)
    {
        if(i % rn == 0)
        {
            block_id++;
        }
        blocks[block_id] += a[i]; //for sum query
    }

    cout << query(blocks, a, 2, 8, rn) << nn;
    update(blocks, a, 2, 15, rn);
    cout << query(blocks, a, 2, 8, rn) << nn;



    return 0;
}



