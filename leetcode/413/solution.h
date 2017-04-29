// solution: 3ms, 15 cases
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int result = 0;
        int begin = 0, end = 2;
        while (end < A.size()) {
            if (end - begin == 2 && A[begin] + A[end] != A[begin + 1] << 1) {
                ++begin;
                ++end;
            } else {
                while (end < A.size() && A[end - 2] + A[end] == (A[end - 1] << 1)) {
                    ++end;
                }
                result += GetArithmeticCount(end - begin);
                begin = end - 2;
            }
        }
        return result;
    }
private:
    int GetArithmeticCount(int length) {
        return (length - 1) * (length - 2) / 2;
    }
};