#include <iostream>
#include "solution.h"

int main() {
    // build tree
    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node3.left = &node5;
    node3.right = &node1;

    node5.left = &node6;
    node5.right = &node2;

    node1.left = &node0;
    node1.right = &node8;

    node2.left = &node7;
    node2.right = &node4;

    // solution
    Solution slt;
    TreeNode* ancestor = slt.lowestCommonAncestor(&node3, &node4, &node6);
    if (ancestor) {
        std::cout << "ancestor: " << ancestor->val << std::endl;
    }

    return 0;
}