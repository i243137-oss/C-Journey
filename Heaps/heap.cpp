#include <iostream>
using namespace std;

// ===================== MAX HEAP =====================
class MaxHeap {
    int *arr;
    int size;
    int totalSize;

public:
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    void insert(int num) {
        if(size == totalSize){
            cout << "MaxHeap is Full!" << endl;
            return;
        }

        arr[size] = num;
        int index = size;
        size++;

        // Bubble Up (Max Heap condition)
        while(index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << num << " inserted in MaxHeap." << endl;
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && arr[left] > arr[largest])
            largest = left;
        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void deleteNode() {
        if(size == 0){
            cout << "MaxHeap is Empty!" << endl;
            return;
        }

        cout << arr[0] << " deleted from MaxHeap." << endl;
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    void print() {
        cout << "MaxHeap: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};



// ===================== MIN HEAP =====================
class MinHeap {
    int *arr;
    int size;
    int totalSize;

public:
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    void insert(int num) {
        if(size == totalSize){
            cout << "MinHeap is Full!" << endl;
            return;
        }

        arr[size] = num;
        int index = size;
        size++;

        // Bubble Up (Min Heap condition)
        while(index > 0 && arr[(index - 1) / 2] > arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << num << " inserted in MinHeap." << endl;
    }

    void heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && arr[left] < arr[smallest])
            smallest = left;
        if(right < size && arr[right] < arr[smallest])
            smallest = right;

        if(smallest != index) {
            swap(arr[index], arr[smallest]);
            heapify(smallest);
        }
    }

    void deleteNode() {
        if(size == 0){
            cout << "MinHeap is Empty!" << endl;
            return;
        }

        cout << arr[0] << " deleted from MinHeap." << endl;
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    void print() {
        cout << "MinHeap: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};



// ===================== MAIN FUNCTION =====================
int main() {

    MaxHeap maxH(10);
    MinHeap minH(10);

    // Insert values
    maxH.insert(40);
    maxH.insert(50);
    maxH.insert(30);
    maxH.insert(10);
    maxH.insert(60);

    minH.insert(40);
    minH.insert(50);
    minH.insert(30);
    minH.insert(10);
    minH.insert(60);

    // Print both heaps
    cout << endl;
    maxH.print();
    minH.print();

    // Delete root from both
    cout << endl;
    maxH.deleteNode();
    minH.deleteNode();

    // Print after deletion
    cout << endl;
    maxH.print();
    minH.print();

    return 0;
}
