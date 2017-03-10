class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int start = 0, end = 0;
        int length = nums.size() + 1;
        int sum = 0;

        sum += nums[0];
        while (start != nums.size()) {
            if (sum >= s) {
                if (length > (start - end + 1)) {
                    length = start - end + 1;
                }
                sum -= nums[end];
                ++end;
            } else {
                ++start;
                sum += nums[start];
            }
        }

        return (length == nums.size() + 1 ? 0 : length);
    }
};
