// solution1: 53ms, 84 cases
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums.front();
        int res = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] < min) {
                res += (min - nums[i]) * i;
                min = nums[i];
            } else {
                res += nums[i] - min;
            }
        }
        return res;
    }
};

// solution2: 86ms, 84 cases
class Solution {
public:
    int minMoves(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i != nums.size(); ++i) {
            result += nums[i] - nums[0];
        }
        return result;
    }
};