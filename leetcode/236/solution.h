/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // build path
        std::vector<bool> p_path;
        std::vector<bool> q_path;
        GetPath(root, p, p_path);
        GetPath(root, q, q_path);

        // get ancestor
        TreeNode* node = root;
        for (int i = p_path.size() - 1, j = q_path.size() - 1; i >= 0 && j >= 0 && p_path[i] == q_path[j]; --i, --j) {
            node = p_path[i] ? node->right : node->left;
        }

        return node;
    }

private:
    bool GetPath(TreeNode* cur, TreeNode* node, std::vector<bool>& path) {
        if (!cur) { return false; }
        if (cur == node) { return true; }

        if (GetPath(cur->left, node, path)) {
            path.push_back(false);  // false: go left
        } else if (GetPath(cur->right, node, path)) {
            path.push_back(true);   // true: go right
        } else {
            return false;
        }
        return true;
    }
};