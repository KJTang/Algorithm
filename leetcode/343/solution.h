// solution: 0ms, 50 cases
class Solution {
public:
    int integerBreak(int n) {
        // special case
        if (n == 2) { return 1; }
        if (n == 3) { return 2; }
        // init
        for (int i = 0; i != 60; ++i) {
            cache[i] = 0;
        }
        // compute
        return RecursiveFunc(n);
    }
private:
    int cache[60];

    int RecursiveFunc(int n) {
        if (n == 1) {
            return 1;
        }
        int max = n;
        int tmp = 0;
        for (int i = 1; i <= (n >> 1); ++i) {
            if (cache[n - i] == 0) {
                cache[n - i] = RecursiveFunc(n - i);
            }
            tmp = cache[n - i] * i;
            if (tmp > max) {
                max = tmp;
            }
        }
        return (cache[n] = max);
    }
};