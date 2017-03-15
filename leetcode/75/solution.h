class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i < two; ) {
            if (nums[i] > 1 && i < two) {
                nums[i] = nums[two];
                nums[two] = 2;
                --two;
            } else if (nums[i] < 1 && i > zero) {
                nums[i] = nums[zero];
                nums[zero] = 0;
                ++zero;
            } else {
                ++i;
            }
        }
    }
};