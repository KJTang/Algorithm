#include <iostream>
#include "RBTree.h"

using namespace std;

int main() {
    RBTree<int> tree;
    for (int i = 0; i != 38; ++i) {
        tree.add(i, i);
    }
    tree.traverse(TraverseOrder::MID_ORDER);
    tree.traverse(TraverseOrder::PRE_ORDER);
    
    tree.remove(1);
    tree.remove(3);
    tree.remove(7);
    tree.remove(15);
    tree.remove(31);
    tree.traverse(TraverseOrder::MID_ORDER);
    tree.traverse(TraverseOrder::PRE_ORDER);
    return 0;
}