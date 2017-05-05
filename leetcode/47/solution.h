// solution: 23ms, 30 cases
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<bool> flag(nums.size(), true);
        
        std::sort(nums.begin(), nums.end());
        RecursiveFunc(nums, -1, result, flag);

        return result;
    }
private:
    std::vector<int> cur_;

    void RecursiveFunc(const std::vector<int>& nums, int ptr, std::vector<std::vector<int>>& result, std::vector<bool>& flag) {
        if (cur_.size() == nums.size()) {
            result.push_back(cur_);
            return;
        }

        int last_num = nums[0] - 1;
        for (int i = ptr + 1, j = 0; j != nums.size(); ++i, ++j) {
            if (i == nums.size()) { i = 0; }
            if (flag[i] && last_num != nums[i]) {
                last_num = nums[i];

                cur_.push_back(nums[i]);
                flag[i] = false;
                RecursiveFunc(nums, i, result, flag);
                flag[i] = true;
                cur_.pop_back();
            }
        }
    }
};
