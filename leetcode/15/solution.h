// solution: 112ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() >= 3) {
            std::sort(nums.begin(), nums.end());
            int length = nums.size();
            int last = nums[0] - 1;
            for (int i = 0; i != length - 2; ++i) {
                // avoid duplicates
                if (nums[i] == last) {
                    continue;
                }
                // avoid useless compute
                if ((last = nums[i]) > 0) {
                    break;
                }
                // find 2 other nums
                int start = i + 1;
                int end = length - 1;
                while (start < end) {
                    if (nums[start] + nums[end] > -nums[i]) {
                        --end;
                    } else if (nums[start] + nums[end] < -nums[i]) {
                        ++start;
                    } else {
                        result.push_back({nums[i], nums[start], nums[end]});
                        int last_end = nums[end];
                        while (start < end && nums[end] == last_end) {
                            --end;
                        }
                        int last_start = nums[start];
                        while (start < end && nums[start] == last_start) {
                            ++start;
                        }
                    }
                }
            }
        }
        return result;
    }
};
