// solution 1: use recursive function
class Solution {
public:
    int findMin(vector<int>& nums) {
        return RecursiveFind(0, nums.size() - 1, nums);
    }
private:
    int RecursiveFind(int start, int end, const std::vector<int>& nums) {
        if (nums[start] <= nums[end]) {
            return nums[start];
        }
        int mid = (end - start) / 2 + start;
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        return RecursiveFind(start, end, nums);
    }
};

// solution 2: use iteration
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (end - start) / 2 + start;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};