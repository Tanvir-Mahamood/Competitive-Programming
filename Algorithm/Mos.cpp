//Mos Algorithm
//O(Q*sqrt(N) + QlogQ)

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define ll  long long

int freq[1000001];
int distinct;

struct query
{
    int L, R, q_no;
    int block_no;
    bool operator < (query& q2)
    {
        if(block_no < q2.block_no)    return 1;
        else if(block_no > q2.block_no) return 0;
        else return R < q2.R;
    }
};

void Add(int elem)
{
    if(freq[elem] == 0) distinct++;
    freq[elem]++;
}
void Remove(int elem)
{
    freq[elem]--;
    if(freq[elem] == 0) distinct--;
}

void adjust(int& curr_l, int& curr_r, query& q, vector<int> & ar)
{
    while(curr_l <q.L)
    {
        Remove(ar[curr_l]);
        curr_l ++;
    }
    while(curr_l > q.L)
    {
        curr_l--;
        Add(ar[curr_l]);
    }

    while(curr_r < q.R)
    {
        curr_r ++;
        Add(ar[curr_r]);
    }
    while(curr_r > q.R)
    {
        Remove(ar[curr_r]);
        curr_r--;
    }
}

void solve(vector<query> &queries, vector<int> & ar)
{
    vector<int> answer(queries.size());

    sort(queries.begin(), queries.end());

    memset(freq, 0, sizeof freq);

    distinct = 0;

    int curr_l = queries[0].L;
    int curr_r = queries[0].R;

    for(int i=queries[0].L; i<=queries[0].R; i++) // brute force for first query
    {
        Add(ar[i]);
    }
    answer[queries[0].q_no] = distinct;
    for(int i=1; i<queries.size(); i++)
    {
        adjust(curr_l, curr_r, queries[i], ar);
        answer[queries[i].q_no] = distinct;
    }

    for(int x: answer)
    {
        cout << x << nn;
    }

}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n, q, i, u, v;
    cin >> n;
    vector<int> ar(n);
    for(i=0; i<n; i++) cin >> ar[i];
    cin >> q;
    vector<query> queries(q);
    int rn = sqrt(n);
    for(i=0; i<q; i++)
    {
        cin >> u >> v; //1 based
        queries[i].L    = u - 1;//making 0 based
        queries[i].R    = v - 1;
        queries[i].q_no = i;
        queries[i].block_no = u / rn;
    }
    solve(queries, ar);


    return 0;
}



