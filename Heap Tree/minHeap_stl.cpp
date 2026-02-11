#include <bits/stdc++.h>
using namespace std;

int main() {

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Min element: " << minHeap.top() << endl;

    cout << "All elements (ascending order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
