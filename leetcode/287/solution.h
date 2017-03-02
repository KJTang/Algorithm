// // solution1: need O(n) space which is not correct

// #include <vector>
// #include <set>

// using std::vector;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for (int i = 0; i != nums.size(); ++i) {
//             auto it = set_.insert(nums[i]);
//             if (it != set_.begin() && *(--it) == nums[i]) {
//                 return nums[i];
//             }
//         }
//         return 0;
//     }
// private:
//     std::multiset<int> set_;
// };


// solution2: thanks to http://blog.csdn.net/monkeyduck/article/details/50439840
#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
