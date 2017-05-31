
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// solution: 9ms, 74 cases
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return IsValid(root);
    }

private:
    bool is_init = false;
    int last_val_ = INT_MIN;

    bool IsValid(TreeNode* node) {
        if (!node) {
            return true;
        }

        // left
        if (!IsValid(node->left)) {
            return false;
        }
        // mid
        if (!is_init) {
            last_val_ = node->val;
            is_init = true;
        } else {
            if (node->val <= last_val_) {
                return false;
            }
            last_val_ = node->val;
        }
        // right
        if (!IsValid(node->right)) {
            return false;
        }

        return true;
    }
};