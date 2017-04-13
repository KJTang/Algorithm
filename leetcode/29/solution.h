// solution: 19ms
#include <climits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return 0;
        }
        rem = dividend;
        div = divisor;
        if (dividend < 0) {
            rem *= -1;
            sign = !sign;
        }
        if (divisor < 0) {
            div *= -1;
            sign = !sign;
        }
        long long result = 0;
        long long step = Divide(div);
        while (step != 0) {
            result += step;
            step = Divide(div);
        }
        int int_result = result;
        if (result > INT_MAX && sign) {
            return INT_MAX;
        } else {
            return sign ? result : -result;
        }
    }
private:
    long long rem;
    long long div;
    bool sign = true;

    long long Divide(long long divisor) {
        if (rem < divisor) {
            return 0;
        }
        long long result = 1;
        while (rem >= divisor) {
            divisor = divisor << 1;
            result = result << 1;
        }
        divisor = divisor >> 1;
        result = result >> 1;
        rem -= divisor;
        return result;
    }
};