// solution: 3ms, 47 cases
class Solution {
public:
    int integerReplacement(int n) {
        std::map<int, int> cache;
        return DP(n, cache);
    }
private:
    int DP(unsigned int n, std::map<int, int>& cache) {
        if (n == 1) {
            return 0;
        }
        // cache hit
        auto it = cache.find(n);
        if (it != cache.end()) {
            return it->second;
        }
        // cache miss
        if (n % 2 == 0) {
            return DP(n / 2, cache) + 1;
        } else {
            int cnt1 = DP(n + 1, cache);
            int cnt2 = DP(n - 1, cache);
            return cache[n] = std::min(cnt1, cnt2) + 1;
        }
    }
};