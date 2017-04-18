// solution: 6ms, 596 cases, https://discuss.leetcode.com/topic/21882/my-16ms-c-dp-solution-with-short-explanation
class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> ugly_nums(n);
        ugly_nums[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int p = 0;
        while (p != n - 1) {
            int new2 = ugly_nums[p2] * 2;
            int new3 = ugly_nums[p3] * 3;
            int new5 = ugly_nums[p5] * 5;
            ++p;
            ugly_nums[p] = std::min({new2, new3, new5});
            if (new2 == ugly_nums[p]) {
                ++p2;
            }
            if (new3 == ugly_nums[p]) {
                ++p3;
            }
            if (new5 == ugly_nums[p]) {
                ++p5;
            }
        }
        return ugly_nums.back();
    }
};