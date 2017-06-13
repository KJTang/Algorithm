/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// solution: 36ms, 18 cases
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        int height = GetTreeHeight(root);
        while (root) {
            int right_height = GetTreeHeight(root->right);
            if (right_height == (height - 1)) {
                root = root->right;
                count += (1 << height);
            } else {
                root = root->left;
                count += (1 << (height - 1));
            }
            --height;
        }
        return count;
    }
private:
    int GetTreeHeight(TreeNode* node) {
        int height = -1;
        while (node) {
            node = node->left;
            ++height;
        }
        return height;
    }
};


// solution: 79ms, 18 cases
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int height = GetTreeHeight(root);

        // low: last level min node id 
        // high: last level max node id
        int low = 1 << (height - 1);
        int high = (1 << height) - 1;

        while (low < high) {
            int mid = (low + high) / 2 + 1;
            if (GetNthNode(mid, root, height) != nullptr) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
private:
    int GetTreeHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->left;
            ++height;
        }
        return height;
    }

    TreeNode* GetNthNode(int n, TreeNode* node, int height) {   // height >= 2
        int bit = 1 << (height - 2);
        while (node && bit) {
            node = (bit & n) ? node->right : node->left;
            bit >>= 1;
        }
        return node;
    }
};