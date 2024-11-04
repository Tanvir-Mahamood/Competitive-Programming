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

    tree[node] = max(tree[left] , tree[right]);
}

int query(int node, int b, int e, int i, int j) // Highest element in range[i,j]
{
    if(i > e || j < b)   return INT_MIN;          //Out of given range
    if(b >= i && e <= j) return tree[node];       //Relevant Segment

    int left  = node * 2;
    int right = node * 2 + 1;
    int mid   = (b + e) / 2;

    int p1    = query(left, b, mid, i, j);
    int p2    = query(right, mid + 1, e, i, j);

    return max(p1 , p2);
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

    tree[node] = max(tree[left] , tree[right]);
}

int main() {
    int n, i;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);

    update(1,1,n,4,-1);
    cout << query(1,1,n,2,6) << nn;

    return 0;
}






