// solution: 12ms, 25 cases
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<bool> flag(nums.size(), true);
        DFS(nums, result, flag);
        return result;
    }
private:
    std::vector<int> cur_;

    void DFS(const std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<bool>& flag) {
        if (cur_.size() == nums.size()) {
            result.push_back(cur_);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (flag[i]) {
                cur_.push_back(nums[i]);
                flag[i] = false;
                DFS(nums, result, flag);
                flag[i] = true;
                cur_.pop_back();
            }
        }
    }
};