// solution1: use sort: 19ms, 29 cases
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int begin = 0, end = nums.size() - 1; begin < end; ++begin, --end) {
            res += nums[end] - nums[begin];
        }
        return res;
    }
};

// solution2: use quick-select: 152ms / 23ms(use rand), 29 cases
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int median = QuickSelect(nums, 0, nums.size() - 1, nums.size() / 2);
        int result = 0;
        for (int i = 0; i != nums.size(); ++i) {
            result += std::abs(nums[i] - median);
        }
        return result;
    }
private:
    int QuickSelect(std::vector<int>& nums, int begin, int end, int id) {
        // rand
        std::swap(nums[begin], nums[(begin + end) / 2]);
        // sort
        int key = nums[begin];
        int p = begin, q = end;
        while (p <= q) {
            while (p <= q && nums[p] <= key) { ++p; }
            while (p <= q && nums[q] >= key) { --q; }
            if (p > q) {
                break;
            }
            std::swap(nums[p], nums[q]);
        }
        std::swap(nums[--p], nums[begin]);

        if (p - begin > id) {
            return QuickSelect(nums, begin, p - 1, id);
        } else if (p - begin < id) {
            return QuickSelect(nums, p + 1, end, id - (p - begin) - 1);
        } else {
            return nums[p];
        }
    }
};