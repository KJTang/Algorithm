// solution: 0ms, 33 cases; https://discuss.leetcode.com/topic/49238/math-solution-java-solution
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        // make x >= y
        if (x < y) {
            std::swap(x, y);
        }
        if (x == 0) {
            return z == 0;
        } else {
            return z % GCD(x, y) == 0;
        }
    }
private:
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
};