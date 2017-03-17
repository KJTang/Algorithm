// solution1: 0ms
class Solution {
public:
    int uniquePaths(int m, int n) {
        // compute Combination(M, N)
        int M = m + n - 2;
        int N = m - 1;
        long long result = 1;
        for (int i = N + 1; i <= M; ++i) {
            result = result * i / (i - N);
        }
        return result;
    }
};

// solution2: 'long' is not enough to save the result
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         return Combination(m + n - 2, m - 1);
//     }
// private:
//     inline long factorial(long m, long n) {
//         return m <= n ? 1 : m * factorial(m - 1, n);
//     }
//     inline long Combination(long m, long n) {
//         return factorial(m, n) / factorial(m - n, 1);
//     }
// };