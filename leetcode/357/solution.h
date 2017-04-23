// solution: 0ms, 9 cases; Permutation And Combination 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // boundary
        if (n == 0) { return 1; }
        if (n == 1) { return 10; }
        // compute
        int cur = 9;
        for (int i = 1, j = 9; i != n; ++i, --j) {
            cur *= j;
        }
        return cur + countNumbersWithUniqueDigits(n - 1);
    }
};