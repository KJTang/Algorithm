// solution1: 62ms, 29 cases, use Trie
class Solution {
public:    
    struct TreeNode {
        TreeNode* next[2];
        TreeNode() { 
            next[0] = nullptr; 
            next[1] = nullptr; 
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = BuildTree(nums);
        
        for (auto i : nums) {
            res = std::max(res, TreeHelper(root, i));
        }
        
        return res;
    }
private:
    TreeNode* BuildTree(const vector<int>& nums) {
        TreeNode* root = new TreeNode();
        TreeNode* cur = nullptr;
        int n = nums.size();
        for (int i = 0; i != n; ++i) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (!(cur->next[index])) {
                    cur->next[index] = new TreeNode();
                }
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int TreeHelper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int index = ((num >> i) & 1) ? 0 : 1;
            res <<= 1;
            if (cur->next[index]) {
                res |= 1;
                cur = cur->next[index];
            } else {
                // res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
};

// solution2: 172ms, 29 cases, https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_num = 0, mask = 0;
        for (int i = 1 << 30; i != 0; i >>= 1){
            mask = mask | i;
            std::set<int> set;
            for (int j = 0; j != nums.size(); ++j) {
                set.insert(nums[j] & mask);
            }
            int tmp = max_num | i;
            for (auto it = set.begin(); it != set.end(); ++it) {
                // if tmp ^ a = b, it means a ^ b = tmp
                auto find = set.find(tmp ^ (*it));
                if (find != set.end()) {
                    max_num = tmp;
                    break;
                }
            }
        }
        return max_num;
    }
};