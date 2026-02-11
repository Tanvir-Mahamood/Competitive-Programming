#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Heapify Down (used in extract, build, delete)
    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify Up (used in insert, increaseKey)
    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] < heap[i]) { // parent < child
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

public:
    MaxHeap() {} // Constructor

    // Build Heap from array (O(n))
    void buildHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size()/2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    // Insert element
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Get maximum
    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Extract maximum
    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return root;
    }

    // Increase key at index
    void increaseKey(int i, int newVal) {
        if (i >= heap.size() || newVal < heap[i]) {
            cout << "Invalid operation!\n";
            return;
        }

        heap[i] = newVal;
        heapifyUp(i);
    }

    // Decrease key at index
    void decreaseKey(int i, int newVal) {
        if (i >= heap.size() || newVal > heap[i]) {
            cout << "Invalid operation!\n";
            return;
        }

        heap[i] = newVal;
        heapifyDown(i);
    }

    // Delete element at index
    void deleteAtIndex(int i) {
        if (i >= heap.size()) {
            cout << "Invalid index!\n";
            return;
        }

        increaseKey(i, INT_MAX);
        extractMax();
    }

    // Heap Sort (returns sorted vector)
    vector<int> heapSort() {
        MaxHeap temp = *this;  // copy heap
        vector<int> sorted;

        while (!temp.heap.empty())
            sorted.push_back(temp.extractMax());

        reverse(sorted.begin(), sorted.end());
        return sorted;
    }

    void printHeap() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

    int size() {
        return heap.size();
    }
};

//////////////////////////////////////////////////////
//                  DRIVER CODE
//////////////////////////////////////////////////////

int main() {
    MaxHeap h;

    int choice;
    while (true) {
        cout << "\n===== MAX HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Get Max\n";
        cout << "3. Extract Max\n";
        cout << "4. Increase Key\n";
        cout << "5. Decrease Key\n";
        cout << "6. Delete at Index\n";
        cout << "7. Build Heap from Array\n";
        cout << "8. Print Heap\n";
        cout << "9. Heap Sort\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) { // Insert
            int val;
            cout << "Enter value: ";
            cin >> val;
            h.insert(val);
        }

        else if (choice == 2) { // Get Max
            cout << "Max: " << h.getMax() << endl;
        }

        else if (choice == 3) { // Extract Max
            cout << "Extracted: " << h.extractMax() << endl;
        }

        else if (choice == 4) { // Increase Key
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            h.increaseKey(idx, val);
        }

        else if (choice == 5) { // Decrease Key
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            h.decreaseKey(idx, val);
        }

        else if (choice == 6) { // Delete at Index
            int idx;
            cout << "Enter index: ";
            cin >> idx;
            h.deleteAtIndex(idx);
        }

        else if (choice == 7) { // Build Heap from Array
            int n;
            cout << "Enter size of array: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            h.buildHeap(arr);
        }

        else if (choice == 8) { // Print Heap
            h.printHeap();
        }

        else if (choice == 9) { // Heap Sort
            vector<int> sorted = h.heapSort();
            cout << "Sorted Array: ";
            for (int x : sorted)
                cout << x << " ";
            cout << endl;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

/*
insert = O(log n)
extract = O(log n)
buildHeap = O(n)
heapSort = O(n log n)
*/
