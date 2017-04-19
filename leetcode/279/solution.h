// solution: 29ms, 600 cases
// the fastest solution is mathematics solution: https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics

#include <climits>

class Solution {
public:
    int numSquares(int n) {
        int sqrt_n = std::sqrt(n);
        for (int i = sqrt_n; i > sqrt_n / 2; --i) {
            int count = DFS(n - i * i, 1) + 1;
            if (count < min_) {
                min_ = count;
            }
        }
        return min_;
    }

private:
    int min_ = INT_MAX;

    int DFS(int n, int level) {
        // boundary
        if (n == 0) {
            return 0;
        }
        // decrease compute
        if (level >= min_) {
            return level;
        }
        // DFS
        int local_min = INT_MAX;
        int sqrt_n = std::sqrt(n);
        for (int i = sqrt_n; i > sqrt_n / 2; --i) {
            int count = DFS(n - i * i, level + 1) + 1;
            if (count < local_min) {
                local_min = count;
            }
        }
        return local_min;
    }
};