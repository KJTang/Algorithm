// solution: 59ms, 47 cases
// example:
// 2:           0010
// 4:           0100
// 14:          1110
// count_of_1:  1220
// distance = 1 * 2 + 2 * 1 + 2 * 1 + 0 * 3 = 6;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        std::vector<int> count_of_1(32, 0);
        int length = nums.size();
        for (int i = 0; i != length; ++i) {
            for (int j = 0; j != 32; ++j) {
                count_of_1[j] += (nums[i] >> j) & 1;
            }
        }

        int distance = 0;
        for (int i = 0; i != 32; ++i) {
            distance += count_of_1[i] * (length - count_of_1[i]);
        }
        return distance;
    }
};