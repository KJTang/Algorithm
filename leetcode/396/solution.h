// solution1: 9ms, 17 cases
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int F = 0;
        int len = A.size();
        for (int i = 0; i != len; ++i) {
            F += i * A[i];
            sum += A[i];
        }
        int max = F;
        for (int i = len - 1; i != 0; --i) {
            F = F + sum - A[i] * len;
            max = std::max(max, F);
        }
        return max;
    }
};

// solution2: 1472ms, 17 cases
#include <climits>
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int max = INT_MIN;
        for (int i = 0; i != A.size(); ++i) {
            int tmp = F(A, i);
            if (tmp > max) {
                max = tmp;
            }
        }
        return max;
    }
private:
    int F(const std::vector<int>& A, int offset) {
        int result = 0;
        for (int i = 0; i != A.size(); ++i) {
            result += i * (i + offset >= A.size() ? A[i + offset - A.size()] : A[i + offset]);
        }
        return result;
    }
};