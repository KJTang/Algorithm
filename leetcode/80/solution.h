// solution1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_addr = 0;
        int swap_addr = 0;
        int last_num = nums.size() > 0 ? nums[0] - 1 : -1;
        int last_cnt = 0;

        while (cur_addr != nums.size()) {
            int cur_num = nums[cur_addr];
            // swap
            if (swap_addr != 0) {
                nums[cur_addr] = nums[cur_addr - swap_addr];
                nums[cur_addr - swap_addr] = cur_num;
            }
            // detect
            if (last_num == cur_num) {
                ++last_cnt;
                if (last_cnt >= 2) {
                    ++swap_addr;
                }
            } else {
                last_num = cur_num;
                last_cnt = 0;
            }
            // increase
            ++cur_addr;
        }

        return nums.size() - swap_addr;
    }
};

// solution2: https://discuss.leetcode.com/topic/17180/3-6-easy-lines-c-java-python-ruby
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_addr = 0;
        int res_addr = 0;
        while (cur_addr != nums.size()) {
            if (res_addr < 2 || nums[cur_addr] > nums[res_addr - 2]) {
                nums[res_addr] = nums[cur_addr];
                ++res_addr;
            }
            ++cur_addr;
        }
        return res_addr;
    }
};