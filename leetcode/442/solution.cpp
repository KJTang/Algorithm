class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> result;
        for (int i = 0; i != nums.size(); ) {
            if (nums[i] == i+1) {
                nums[i] = -1;
                ++i;
                continue;
            }
            if (nums[i] > 0) {
                int p = nums[i];
                int q = nums[p-1];
                if (q > 0) {    // swap
                    nums[p-1] = -1;
                    nums[i] = q;
                } else {        // count
                    nums[p-1] -= 1;
                    nums[i] = 0;
                }
            } else {
                ++i;
            }
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == -2) {
                result.push_back(i+1);
            }
        }
        return result;
    }
};