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

void solve1()
{
    int arr[] = {1,10,11,9,100};
    int n = sizeof(arr) / sizeof(int);

    int key = 11;
    auto it = find(arr, arr+n, key);
    int index = it - arr;
    if(index == n) cout << "Not found\n";
    else cout << index << nn;
}

void solve2()
{
    vector<int> v = {1,10,11,9,100};
    int n = v.size();

    int key = 11;
    auto it = find(v.begin(), v.end(), key);
    if(it == v.end()) cout << "Not found\n";
    else cout << it - v.begin() << nn;
}

void bin_search()
{
    vector<int> v = {20,30,40,40,40,50,100,1100}; // array should be initially sorted
    int n = v.size();

    int key = 40;

    bool present = binary_search(v.begin(), v.end(), key);
    if(present) cout << "Present\n";
    else cout << "Not present\n";

    //lower bound: >= key
    auto it1 = lower_bound(v.begin(), v.end(), key); cout << it1 - v.begin() << nn;
    //upper bound :  > key
    auto it2 = upper_bound(v.begin(), v.end(), key); cout << it2 - v.begin() << nn;

    cout << "Frequency of " << key << "= " << it2 - it1 << nn;
}

void string_fun()
{
    string word = "I have a apple";
    int indx = word.find("apple");
    cout << indx << nn;

    word.erase(2, 4); // starting index, size of erasable portion
    cout << word << nn;
}



int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve1();
        solve2();
        bin_search();
        string_fun();
    }

    return 0;
}



