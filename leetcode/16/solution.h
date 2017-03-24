// solution: 6ms ~ 9ms
#include <cmath>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 65535;
        int result = 0;
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        int last = nums[0] - 1;
        for (int i = 0; i != length - 2; ++i) {
            if (nums[i] == last) {
                continue;
            }
            last = nums[i];

            int start = i + 1;
            int end = length - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int offset = std::abs(sum - target);
                if (offset == 0) {
                    return sum;
                }
                if (offset < closest) {
                    closest = offset;
                    result = sum;
                }
                // next
                if (sum < target) {
                    ++start;
                } else {
                    --end;
                }
            }
        }
        return result;
    }
};