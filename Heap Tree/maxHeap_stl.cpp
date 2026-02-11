#include <bits/stdc++.h>
using namespace std;

int main() {

    // Default → Max Heap
    priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    cout << "Max element: " << maxHeap.top() << endl;

    cout << "All elements (descending order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}
