// thanks to http://blog.csdn.net/xudli/article/details/46911603

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        if (nums.size() <= 0) {
            return result;
        }

        // left to right
        int left = 1;
        for (int i = 0; i != nums.size(); ++i) {
            left *= nums[i];
            result[i] = left;
        }

        // right to left
        int right = 1;
        for (int i = nums.size()-1; i != 0; --i) {
            result[i] = result[i-1] * right;
            right *= nums[i];
        }
        result[0] = right;

        return result;
    }
};