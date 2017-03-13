class Solution {
public:
    int search(vector<int>& nums, int target) {
        return nums.size() == 0 ? false : SpecialBinarySearch(0, nums.size() - 1, target, nums);
    }
private:
    bool SpecialBinarySearch(int start, int end, int target, const std::vector<int>& nums) {
        // recursive boundary
        if (end - start <= 0) {
            return nums[start] == target ? true : false;
        }
        // mid number
        int mid = (end - start) / 2 + start;
        if (nums[mid] == target) {
            return true;
        }
        // recursive search
        if (nums[start] == nums[end]) { // in this case, we cannot know which side to search
            ++start;
        } else {                        // the same as leetcode 33
            if (nums[mid] >= nums[start]) {
                if (target < nums[mid] && target >= nums[start]) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
        return SpecialBinarySearch(start, end, target, nums);
    }
};