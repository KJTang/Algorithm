// solution: 3ms, 146 cases
class Solution {
public:
    int smallestFactorization(int a) {
        if (a <= 1) {
            return a;
        }

        std::vector<int> result;
        for (int i = 9; i != 1; ) {
            if (a % i == 0) {
                a /= i;
                result.push_back(i);
            } else {
                --i;
            }
        }
        // no answer
        if (a != 1) {
            return 0;
        }
        // to long
        if (result.size() > 10) {
            return 0;
        }
        std:sort(result.begin(), result.end());
        // big than max int
        if (result.size() == 10 && result[0] > 1) {
            return 0;
        }
        int result_int = 0;
        for (auto i : result) {
            result_int *= 10;
            result_int += i;
        }
        return result_int;
    }
};