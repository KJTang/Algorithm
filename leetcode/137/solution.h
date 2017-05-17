// solution: 9ms, 11 cases, https://www.zhihu.com/question/38206659
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit_h = 0, bit_l = 0;
        int old_h = 0, old_l = 0;
        for (int i = 0; i != nums.size(); ++i) {
            old_h = bit_h;
            old_l = bit_l;
            bit_h = (old_h & ~nums[i]) | (old_l & nums[i]);
            bit_l = (old_l & ~nums[i]) | (~old_h & ~old_l & nums[i]);
        }
        return bit_l;
    }
};
