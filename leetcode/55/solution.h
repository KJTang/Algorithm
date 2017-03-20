// solution1: 12ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_step = 0;
        for (int i = 0; i < nums.size() && i <= max_step; ++i) {
            max_step = std::max(nums[i] + i, max_step);
        }
        return max_step >= nums.size() - 1;
    }
};

// solution2: time limit exceeded
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if (nums.empty()) {
//             return false;
//         }
//         return DP(nums, nums.size() - 1);
//     }
// private:
//     bool DP(std::vector<int>& nums, int cur) {
//         if (cur == 0) {
//             return true;
//         }
//         for (int i = 1; i != cur + 1; ++i) {
//             if (nums[cur - i] >= i && DP(nums, cur - i)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };