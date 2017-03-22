// solution1: 12ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
            --i;
        }
        if (i != -1) {
            int j = nums.size() - 1;
            while (j > i) {
                if (nums[j] > nums[i]) {
                    break;
                }
                --j;
            }
            std::swap(nums[i], nums[j]);
        }
        Reverse(nums, i + 1, nums.size() - 1);
    }
private:
    void Reverse(std::vector<int>& nums, int start, int end) {
        if (end <= start) {
            return;
        }
        std::swap(nums[start], nums[end]);
        Reverse(nums, start + 1, end - 1);
    }
};

// solution2: 12ms, use std::sort
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
            --i;
        }
        if (i != -1) {
            int j = nums.size() - 1;
            while (j > i) {
                if (nums[j] > nums[i]) {
                    break;
                }
                --j;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        std::sort(nums.begin() + i + 1, nums.end());
    }
};