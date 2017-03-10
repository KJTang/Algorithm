class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return RecursiveFind(0, nums.size() - 1, nums);
    }

private:
    int RecursiveFind(int start, int end, const std::vector<int>& nums) {
        int mid = (end - start) / 2 + start;
        if (mid > 0 && nums[mid] < nums[mid-1]) {
            end = mid - 1;
        } else if (mid < nums.size() - 1 && nums[mid] < nums[mid+1]) {
            start = mid + 1;
        } else {
            return mid;
        }
        return RecursiveFind(start, end, nums);
    }
};