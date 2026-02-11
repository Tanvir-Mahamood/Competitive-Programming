#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Heapify Down (used in extract, build, delete)
    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify Up (used in insert, decreaseKey)
    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

public:
    MinHeap() {}

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

    // Get minimum
    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Extract minimum
    int extractMin() {
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

    // Decrease key at index (value becomes smaller → move up)
    void decreaseKey(int i, int newVal) {
        if (i >= heap.size() || newVal > heap[i]) {
            cout << "Invalid operation!\n";
            return;
        }

        heap[i] = newVal;
        heapifyUp(i);
    }

    // Increase key at index (value becomes larger → move down)
    void increaseKey(int i, int newVal) {
        if (i >= heap.size() || newVal < heap[i]) {
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

        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Heap Sort (returns sorted vector in ascending order)
    vector<int> heapSort() {
        MinHeap temp = *this;
        vector<int> sorted;

        while (!temp.heap.empty())
            sorted.push_back(temp.extractMin());

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
    MinHeap h;

    int choice;
    while (true) {
        cout << "\n===== MIN HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Get Min\n";
        cout << "3. Extract Min\n";
        cout << "4. Decrease Key\n";
        cout << "5. Increase Key\n";
        cout << "6. Delete at Index\n";
        cout << "7. Build Heap from Array\n";
        cout << "8. Print Heap\n";
        cout << "9. Heap Sort\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            h.insert(val);
        }

        else if (choice == 2) {
            cout << "Min: " << h.getMin() << endl;
        }

        else if (choice == 3) {
            cout << "Extracted: " << h.extractMin() << endl;
        }

        else if (choice == 4) {
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            h.decreaseKey(idx, val);
        }

        else if (choice == 5) {
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            h.increaseKey(idx, val);
        }

        else if (choice == 6) {
            int idx;
            cout << "Enter index: ";
            cin >> idx;
            h.deleteAtIndex(idx);
        }

        else if (choice == 7) {
            int n;
            cout << "Enter size of array: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            h.buildHeap(arr);
        }

        else if (choice == 8) {
            h.printHeap();
        }

        else if (choice == 9) {
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
