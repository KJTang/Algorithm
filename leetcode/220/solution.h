// solution: 23ms, 40 cases, https://discuss.leetcode.com/topic/15199/ac-o-n-solution-in-java-using-buckets-with-explanation/2
#include <climit>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k < 1 || t < 0) {
            return false;
        }
        std::map<long long, long long> remapped_nums;
        for (int i = 0; i != nums.size(); ++i) {
            // divid (t + 1) will make (n * t) ~ ((n + 1) * t - 1) all remapped to n
            long long remapped = ((long long)nums[i] - INT_MIN) / ((long long)t + 1);
            // same bucket
            auto it = remapped_nums.find(remapped);
            if (it != remapped_nums.end() && i - it->second <= k) {
                return true;
            }
            // last bucket
            it = remapped_nums.find(remapped - 1);
            if (it != remapped_nums.end() && i - it->second <= k && std::llabs((long long)nums[i] - nums[it->second]) <= t) {
                return true;
            }
            // next bucket
            it = remapped_nums.find(remapped + 1);
            if (it != remapped_nums.end() && i - it->second <= k && std::llabs((long long)nums[i] - nums[it->second]) <= t) {
                return true;
            }
            remapped_nums[remapped] = i;
        }
        return false;
    }
};