#include <bits/stdc++.h>
#define nn "\n"

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS; // set any name

int main()
{
    PBDS St;
    St.insert(15);
    St.insert(3);
    St.insert(10);
    St.insert(4);
    St.insert(1);
    St.insert(1);

    // k-th largest element at till nog -> O(logn)
    // find_by_order(k) = return the iterator k-th largest element
    // given index, find the value
    for(int i=0; i<St.size(); i++)
    {
        cout << i << " " << *St.find_by_order(i) << nn;
    }

    // order_of_key(k) = return the number of the element of the set which are strictly less than the k
    // given value, return address
    cout << St.order_of_key(8) << nn;

}
