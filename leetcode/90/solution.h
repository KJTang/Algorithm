class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        RecursiveAddSet(-1, nums);
        return result;
    }
private:
    std::vector<std::vector<int>> result;
    std::vector<int> cur_set;

    void RecursiveAddSet(int cur, const std::vector<int>& nums) {
        if (cur == nums.size()) {
            return;
        }
        int last_num;
        if (cur >= 0) {
            cur_set.push_back(nums[cur]);
            last_num = nums[cur] - 1;       // make it different from nums[cur]
        } else {
            last_num = nums[cur+1] - 1;     // make it different from nums[cur+1]
        }
        result.push_back(cur_set);
        for (int i = cur + 1; i != nums.size(); ++i) {
            if (last_num != nums[i]) {
                RecursiveAddSet(i, nums);
                last_num = nums[i];
            }
        }
        cur_set.pop_back();
    }
};