// sort by second element instead of first.

#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;  // Min heap based on second
    }
};

int main() {
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   Compare> pq;

    pq.push({10, 3});
    pq.push({20, 1});
    pq.push({15, 2});

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}
