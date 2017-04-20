// solution: 29ms, 83 cases. same as leetcode 264
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        std::vector<int> ugly_nums(n);
        std::vector<int> prime_ptr(primes.size(), 0);
        std::vector<int> new_nums(primes.size());

        ugly_nums[0] = 1;
        int ptr = 0;
        while (ptr != n - 1) {
            int min_num = INT_MAX;
            for (int i = 0; i != new_nums.size(); ++i) {
                new_nums[i] = ugly_nums[prime_ptr[i]] * primes[i];
                if (new_nums[i] < min_num) {
                    min_num = new_nums[i];
                }
            }
            ugly_nums[++ptr] = min_num;
            for (int i = 0; i != new_nums.size(); ++i) {
                if (new_nums[i] == ugly_nums[ptr]) {
                    ++prime_ptr[i];
                }
            }
        }
        return ugly_nums.back();
    }
};