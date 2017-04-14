// solution: 6ms, 300 cases
class Solution {
public:
    double myPow(double x, int n) {
        return Pow(n >= 0 ? x : 1.0 / x, n);
    }
private:
    double Pow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double half = Pow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};