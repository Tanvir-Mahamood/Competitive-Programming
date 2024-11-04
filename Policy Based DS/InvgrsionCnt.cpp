#include <bits/stdc++.h>
#define nn "\n"

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS; // set any name

int main()
{
    //distinct case
    int n, i;
    cin >> n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    PBDS St;
    int inversion_cnt = 0;
    for(i=0; i<n; i++)
    {
        inversion_cnt += (St.size() - St.order_of_key(arr[i]));
        St.insert(arr[i]);
    }
    cout << inversion_cnt << nn;
}

