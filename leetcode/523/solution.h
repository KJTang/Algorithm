// solution1: 29ms, 75 cases, https://discuss.leetcode.com/topic/80793/java-o-n-time-o-k-space
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::map<int, int> rem;     // key: reminder, value: pos in array
        rem.insert(std::make_pair(0, -1));
        int sum = 0;
        for (int i = 0; i != nums.size(); ++i) {
            sum += nums[i];
            int cur_rem = k ? sum % k : sum;
            auto it = rem.find(cur_rem);
            if (it == rem.end()) {
                rem.insert(std::make_pair(cur_rem, i));
            } else if (i - it->second >= 2) {
                return true;
            }
        }
        return false;
    }
};

// solution2: 73ms, 75 cases, O(n^2)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        for (int i = 0; i < length - 1; ++i) {
            int reminder = nums[i] % k;
            for (int j = i + 1; j < length; ++j) {
                reminder += nums[j];
                if (k) {
                    reminder %= k;
                }
                if (reminder == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};