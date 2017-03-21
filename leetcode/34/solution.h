// solution: 9ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int result = BinarySearch(nums, target, 0, nums.size() - 1);
        if (result == -1) {
            return {-1, -1};
        }
        int start, end;
        int left_result = result, right_result = result;
        do {
            start = left_result;
            left_result = BinarySearch(nums, target, 0, start - 1);
        } while (left_result != -1);
        do {
            end = right_result;
            right_result = BinarySearch(nums, target, end + 1, nums.size() - 1);
        } while (right_result != -1);
        return {start, end};
    }
private:
    int BinarySearch(const std::vector<int>& nums, int target, int start, int end) {
        if (end < start) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (target > nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        return BinarySearch(nums, target, start, end);
    }
};