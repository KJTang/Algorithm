// amazing solution: https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations/2

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result(pow(2, nums.size()), std::vector<int>());
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = 0; j != result.size(); ++j) {
                if ((j >> i) & 1) {
                    result[j].push_back(nums[i]);
                }
            }
        }
        return result;
    }
};