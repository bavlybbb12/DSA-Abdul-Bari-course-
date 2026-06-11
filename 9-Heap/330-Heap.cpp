#include <iostream>
using namespace std;

class MaxHeap {
 private:
    int* arr;
    int size;
    int currentSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int &a, int &b) { int temp = a; a = b; b = temp; }

    void swimup(int index);
    void swimdown(int index);

 public:
    MaxHeap(int si) {
        size = si;
        arr = new int[size];
        currentSize = 0;
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void insert(int val);
    int deleteMax();
    void buildHeap(int arr[], int n);
    void heapSort(int arr[], int n);
    void display();
};

void MaxHeap::swimup(int index) {
    while (index != 0 && arr[index] > arr[parent(index)]) {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}

void MaxHeap::insert(int val) {
    if (currentSize == size) {
        cout << "Heap is full!" << endl;
        return;
    }

    arr[currentSize] = val;
    currentSize++;
    swimup(currentSize - 1);
}

void MaxHeap::swimdown(int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);

    if (l < currentSize && arr[l] > arr[largest]) largest = l;
    if (r < currentSize && arr[r] > arr[largest]) largest = r;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        swimdown(largest);
    }
}

int MaxHeap::deleteMax() {
    if (currentSize == 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int maxVal = arr[0];
    arr[0] = arr[currentSize - 1];
    currentSize--;
    swimdown(0);
    return maxVal;
}

void MaxHeap::buildHeap(int arr[], int n) {
    if (n > size) {
        cout << "Input array is too large!" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        this->arr[i] = arr[i];
    }
    currentSize = n;

    for (int i = parent(currentSize - 1); i >= 0; i--) {
        swimdown(i);
    }
}

void MaxHeap::heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(this->arr[0], this->arr[i]);
        currentSize--;
        swimdown(0);
    }

    currentSize = n;
    for (int i = 0; i < n; i++) {
        arr[i] = this->arr[i];
    }
}

void MaxHeap::display() {
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Test 1: Dynamic Insertion & Priority Queue ===" << endl;
    MaxHeap myQueue(10);
    
    myQueue.insert(40);
    myQueue.insert(20);
    myQueue.insert(50);
    myQueue.insert(10);
    myQueue.insert(30);
    
    cout << "Current Heap Array Structure: ";
    myQueue.display(); 

    cout << "Extracted Max: " << myQueue.deleteMax() << endl;
    cout << "Extracted Max: " << myQueue.deleteMax() << endl;
    cout << "Heap Array after Extractions: ";
    myQueue.display();

    cout << "\n=== Test 2: Bulk O(n) Heapify & Heap Sort ===" << endl;
    int unsortedData[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(unsortedData) / sizeof(unsortedData[0]);

    MaxHeap sorter(10);
    cout << "Original Unsorted Array: ";
    for(int x : unsortedData) cout << x << " ";
    cout << endl;

    sorter.heapSort(unsortedData, n);
    cout << "Array After Running Heap Sort: ";
    for(int i = 0; i < n; i++) {
        cout << unsortedData[i] << " ";
    }
    cout << endl;

    return 0;
}