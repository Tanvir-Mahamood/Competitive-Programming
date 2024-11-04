#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

#define mx 100001
int arr[mx];
int tree[mx * 3];

void init(int node, int b, int e) //Tree implementation
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) // Sum of elements of range[i,j]
{
    if(i > e || j < b)   return 0;          //Out of given range
    if(b >= i && e <= j) return tree[node]; //Relevant Segment

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (b + e) / 2;

    int p1    = query(left, b, mid, i, j);
    int p2    = query(right, mid + 1, e, i, j);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int new_value) //update i-th index
{
    if(i > e || i < b)   return;          //Out of given range
    if(b >= i && e <= i) //Relevant Segment
    {
        tree[node] = new_value;
        return;
    }

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (b + e) / 2;

    update(left, b, mid, i, new_value);
    update(right, mid + 1, e, i, new_value);

    tree[node] = tree[left] + tree[right];
}

int main() {
    int n, i;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);

    //for(i=1; i<n*3; i++) cout << tree[i] << " ";
    //cout << query(1, 1, n, 2, 6) << nn; //sum of range[2,6]
    update(1,1,n,5,9);
    for(i=1; i<n*3; i++) cout << tree[i] << " ";



    return 0;
}

/*
arr = {4,-9,3,7,1,0,2}

                                                                        node-1 (8) [1,7]
                               node-2 (5) [1,4]                                                                node-3 (3) [5,7]
           node-4 (-5) [1,2]                    node-5 (10) [3,4]                            node-6 (1) [5,6]                     node-7 (2) [7,7]
node-8 (4) [1,1]    node-9 (-9) [2,2]   node-10 (3) [3,3]   node-11 (7) [4,4]   node-12 (1) [5,5]   node-13 (0) [6,6]
*/



