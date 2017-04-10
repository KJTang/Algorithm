// solution1: 112ms, similar to leetcode 496
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> result(nums.size(), -1);
        std::vector<std::pair<int, int>> num_stack;

        for (int i = 0; i != nums.size(); ++i) {
            while (!num_stack.empty() && num_stack.back().second < nums[i]) {
                result[num_stack.back().first] = nums[i];
                num_stack.pop_back();
            }
            num_stack.push_back(std::make_pair(i, nums[i]));
        }
        // circle
        if (!num_stack.empty()) {
            for (int i = 0; i <= num_stack.front().first; ++i) {
                while (!num_stack.empty() && num_stack.back().second < nums[i]) {
                    result[num_stack.back().first] = nums[i];
                    num_stack.pop_back();
                }
            }
        }

        return result;
    }
};

// solution2: 192ms
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> result(nums.size(), -1);
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i + 1; j != i; ++j) {
                if (j == nums.size()) {     // go back
                    j = -1;
                    continue;
                }
                if (nums[i] < nums[j]) {
                    result[i] = nums[j];
                    break;
                }
            }
        }
        return result;
    }
};