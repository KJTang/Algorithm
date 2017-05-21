// solution: 16ms, 30 cases, https://www.zhihu.com/question/38206659
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // get res1 ^ res2
        int result = 0;
        for (int i = 0; i != nums.size(); ++i) {
            result ^= nums[i];
        }
        // get one of bits that res1 and res2 different with
        int bit = 1;
        while ((bit & result) == 0) {
            bit <<= 1;
        }
        // divid nums into 2 part, res1 and res2 must in different part
        int res1 = 0, res2 = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if ((bit & nums[i]) == 0) {
                res1 ^= nums[i];
            } else {
                res2 ^= nums[i];
            }
        }
        return {res1, res2};
    }
};