#include <iostream>
#include <cstdlib>

using namespace std;

const int LENGTH = 10;
// int arr[LENGTH] = {3, 2, 7, 9, 8, 1, 0, 4, 6, 5};
int arr[LENGTH] = {9, 8, 7, 2, 5, 2, 3, 2, 1, 0};

void quickSort(int arr[], int front, int end);

void test(int arr[]) {
    for (int i = 0; i != LENGTH; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    test(arr);
    srand(time(0));
    quickSort(arr, 0, LENGTH-1);
    test(arr);
    return 0;
}

void quickSort(int arr[], int front, int end) {
    if (front >= end) {
        return;
    }

    // random select
    int random = rand()%(end-front+1)+front;
    int temp = arr[end];
    arr[end] = arr[random];
    arr[random] = temp;

    // sort
    int key = arr[end];
    int i = front-1, j = front;
    for ( ; j != end; ++j) {
        if (arr[j] <= key) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;

    quickSort(arr, front, i);
    quickSort(arr, i+2, end);
}