/* 
 *  select i-small number in array
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int LENGTH = 10;
// int arr[LENGTH] = {3, 2, 7, 9, 8, 1, 0, 4, 6, 5};
int arr[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int randomPatition(int arr[], int front, int end);
int select(int arr[], int front, int end, int i); // select i-small number 

int main() {
    srand(time(0));
    cout<<select(arr, 0, LENGTH-1, 5)<<endl;
    return 0;
}

int randomPatition(int arr[], int front, int end) {
    int random = rand()%(end-front+1)+front;
    int temp = arr[end];
    arr[end] = arr[random];
    arr[random] = temp;

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

    return i+1;
}

int select(int arr[], int front, int end, int i) {
    if (front == end) {
        return arr[front];
    }

    int partition = randomPatition(arr, front, end);
    int pos = partition-front+1;
    if (pos == i) {
        return arr[partition];
    }
    if (pos < i) {
        return select(arr, partition+1, end, i-pos);
    } else {
        return select(arr, front, partition-1, i);
    }
}