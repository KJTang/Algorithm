#include <iostream>

using namespace std;

const int LENGTH = 10;
int arr[LENGTH] = {3, 2, 7, 9, 8, 1, 0, 4, 6, 5};

void maxHeapify(int arr[], int node, int length);
void heapSort(int arr[]);

void test(int arr[]) {
    for (int i = 0; i != LENGTH; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    test(arr);
    heapSort(arr);
    test(arr);
    return 0;
}

void maxHeapify(int arr[], int node, int length) {
    int l = node * 2 + 1; // left child
    int r = node * 2 + 2; // right child
    // find largest one
    int largest = node;
    if (l < length && arr[l] > arr[largest]) { // if left child > parent
        largest = l;
    }
    if (r < length && arr[r] > arr[largest]) { // if right child > parent
        largest = r;
    }
    // if node isn't the largest one
    if (largest != node) {
        int temp = arr[node];
        arr[node] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, length);
    }
}

void heapSort(int arr[]) {
    // build heap
    for (int i = LENGTH/2; i >= 0; --i) {
        maxHeapify(arr, i, LENGTH);
    }
    // sort
    for (int i = LENGTH-1; i != 0; --i) {
        // put the largest num to end of array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // build heap, notice that the length of heap should be 1 less than before
        maxHeapify(arr, 0, i);
    }
}