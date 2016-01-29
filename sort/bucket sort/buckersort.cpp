#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 10;
float arr[LENGTH] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

// bucket node
struct Node{
    float data;
    Node *next;
};

void bucketSort(float arr[], int length);

void test(float arr[]) {
    for (int i = 0; i != LENGTH; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    test(arr);
    bucketSort(arr, LENGTH);
    test(arr);
    return 0;
}

void bucketSort(float arr[], int length) {
    // create bucket
    Node bucket[length];
    for (int i = 0; i != length; ++i) {
        bucket[i].next = NULL;
    }
    // put data into bucket
    for (int i = 0; i != length; ++i) {
        int cur = arr[i] * 10;
        Node *pre = &bucket[cur];
        Node *node = pre->next;
        while (node && node->data < arr[i]) {
            pre = node;
            node = node->next;
        }
        Node *newnode = new Node();
        newnode->data = arr[i];
        newnode->next = node;
        pre->next = newnode;
    }
    // get data from bucket
    int i = 0;
    for (int j = 0; j != length; ++j) {
        Node *node = bucket[j].next;
        while (node) {
            arr[i] = node->data;
            ++i;

            Node *temp = node;
            node = node->next;
            delete temp; // remember to release memory
        }
        bucket[j].next = NULL;
    }
}