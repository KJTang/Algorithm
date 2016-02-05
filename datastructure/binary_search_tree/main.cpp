#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {
    BSTree<int> tree;
    tree.add(15, 15);
    tree.add(8, 8);
    tree.add(6, 6);
    tree.add(7, 7);
    tree.add(12, 12);
    tree.add(11, 11);
    tree.add(9, 9);
    tree.add(20, 20);
    tree.add(18, 18);
    tree.add(25, 25);
    tree.add(23, 23);

    tree.traverse(TraverseOrder::MID_ORDER);
    tree.traverse(TraverseOrder::PRE_ORDER);

    return 0;
}