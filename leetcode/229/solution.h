// thanks to http://www.jianshu.com/p/dfd676b71ef0

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        // vote
        int num1 = 0, num2 = 1;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (num1 == nums[i]) {
                ++cnt1;
            } else if (num2 == nums[i]) {
                ++cnt2;
            } else if (cnt1 == 0) {
                num1 = nums[i];
                ++cnt1;
            } else if (cnt2 == 0) {
                num2 = nums[i];
                ++cnt2;
            } else {
                --cnt1;
                --cnt2;
            }
        }

        // make sure cnt1 & cnt2 > n/3
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (num1 == nums[i]) {
                ++cnt1;
            }
            if (num2 == nums[i]) {
                ++cnt2;
            }
        }
        int condition = nums.size() / 3;
        if (cnt1 > condition) {
            result.push_back(num1);
        }
        if (cnt2 > condition && num1 != num2) {
            result.push_back(num2);
        }

        return result;
    }
};