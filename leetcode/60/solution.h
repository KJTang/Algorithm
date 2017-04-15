// solution: 3ms, 200 cases

// for an example: 
// n == 3, then str should be: "123"
// notice that: 
// when k = 1, 2: str[0] = '1'
// when k = 3, 4: str[0] = '2'
// when k = 5, 6: str[0] = '3'
// so through k we can compute the next header character of str
// 
// make n == 4, k == 6, str == "1234"
// (0)
// --k, k == 5 (make compute easier)
// (1)
// k = 5, i.e. k < 6, length of substr is 3 (k_cache[3] == 6), 
// so substr is "234", the new header of "234" is '4'
// then substr should be "423", str should be: "1423"
// k -= 4, now k == 1, go on
// (2)
// k = 1, i.e. k < 2, length of substr is 2 (k_cache[2] == 2), 
// so substr is "23", the new header of "23" is '3'
// then substr should be "32", str should be: "1432"
// k -= 1, now k == 0, break

class Solution {
public:
    string getPermutation(int n, int k) {
        std::string str(n, '1');
        for (int i = 0; i != n; ++i) {
            str[i] += i;
        }

        int str_begin = 0;
        --k;
        while (k > 0) {
            // find substr 
            int start = 0;
            int factor = 0;
            for (int i = 0; i != k_cache.size(); ++i) {
                if (k < k_cache[i]) {
                    factor = k_cache[i - 1];
                    start = str.size() - i;
                    break;
                }
            }
            int offset = k / factor;
            int end = start + offset;
            // change header
            int temp = str[end];
            for (int i = end; i != start; --i) {
                str[i] = str[i - 1];
            }
            str[start] = temp;
            // next
            k -= offset * factor;
        }

        return str;
    }
private:
    std::vector<int> k_cache = {
        0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
    };
};