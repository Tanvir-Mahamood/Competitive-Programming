#include <bits/stdc++.h>
#define nn "\n"

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS; // set any name

int main()
{
    PBDS St; // ({value,index})
    St.insert({15,0});
    St.insert({3,1});
    St.insert({10,2});
    St.insert({4,3});
    St.insert({1,4});
    St.insert({1,5});

    // k-th largest element at till nog -> O(logn)
    for(int i=0; i<St.size(); i++)
    {
        cout << i << " " << St.find_by_order(i)->first << " " << St.find_by_order(i)->second <<nn;
    }

   // cout << St.order_of_key(5) << nn;

}

