// solution: 6ms, 1012 cases
class Solution {
public:
    bool isUgly(int num) {
        // boundary
        if (num == 0) {
            return false;
        } else if (num == 1) {
            return true;
        }
        // divid by 2, 3, 5
        if (num % 2 == 0) {
            num >>= 1;
        } else if (num % 3 == 0) {
            num /= 3;
        } else if (num % 5 == 0) {
            num /= 5;
        } else {
            return false;
        }
        return isUgly(num);
    }
};