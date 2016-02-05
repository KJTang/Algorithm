#include <iostream>
#include "BTree.h"

using namespace std;

int main() {
    srand(time(0));
    int count = 50;

    BTree<int> tree;
    for (int i = 0; i != count; ++i) {
        tree.insert(i, i);
    }
    tree.traverse();

    int deleteCount = rand()%count;
    for (int i = 0; i != deleteCount; ++i) {
        tree.remove(rand()%count);
        tree.traverse();
    }

    // tree.remove(4);
    // tree.traverse();

    // tree.remove(1);
    // tree.traverse();

    // tree.remove(11);
    // tree.traverse();

    // tree.remove(3);
    // tree.traverse();

    // tree.remove(12);
    // tree.traverse();

    // tree.remove(7);
    // tree.traverse();

    return 0;
}