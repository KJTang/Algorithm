// solution1: 25ms, 8266 cases
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int max_bit = 1 << 30;
        for (int i = 31; i >= 0; --i) {
            if (n & max_bit) {
                break;
            }
            max_bit >>= 1;
        }
        int result = 0;
        while (max_bit > 0 && (m & max_bit) == (n & max_bit)) {
            result |= (m & max_bit);
            max_bit >>= 1;
        }
        return result;
    }
};

// solution2: 42ms, 8266 cases
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int m_max_bit = 0, n_max_bit = 0;
        for (int i = 31; i >= 0; --i) {
            if (m >= cache[i]) {
                m_max_bit = i;
                break;
            }
        }
        for (int i = 31; i >= 0; --i) {
            if (n >= cache[i]) {
                n_max_bit = i;
                break;
            }
        }

        if (m_max_bit != n_max_bit) {
            return 0;
        }
        int result = 0;
        int max_bit = m_max_bit;
        while (max_bit >= 0 && (m & cache[max_bit]) == (n & cache[max_bit])) {
            result |= (m & cache[max_bit]);
            --max_bit;
        }
        return result;
    }
private:
    int cache[32] = {
        0, 1, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 
        1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 
        1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 
        1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30 
    };
};
