// solution: 3ms
class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> cache(s.size(), -1);
        return s.empty() ? 0 : DP(s, 0, cache);
    }
private:

    int DP(const std::string& s, int i, std::vector<int>& cache) {
        // boundary
        if (i == s.size() - 1) {
            return s[i] == '0' ? 0 : 1;
        }
        if (i == s.size() - 2 && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))) {
            return s[i + 1] == '0' ? 1 : 2;
        }
        if (s[i] == '0') {
            return 0;
        }
        // dp
        int cur = 0;
        if (s[i + 1] == '0' && (s[i] == '1' || s[i] == '2')) {
            if (cache[i + 2] == -1) {
                cache[i + 2] = DP(s, i + 2, cache);
            }
            cur = cache[i + 2];
        } else if ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')) {
            if (cache[i + 2] == -1) {
                cache[i + 2] = DP(s, i + 2, cache);
            }
            if (cache[i + 1] == -1) {
                cache[i + 1] = DP(s, i + 1, cache);
            }
            cur = cache[i + 2] + cache[i + 1];
        } else {
            if (cache[i + 1] == -1) {
                cache[i + 1] = DP(s, i + 1, cache);
            }
            cur = cache[i + 1];
        }
        return cur;
    }
};
