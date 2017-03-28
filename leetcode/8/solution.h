#include <climits>

// solution1: 16ms
class Solution {
public:
    int myAtoi(string str) {
        if (!str.size()) {
            return 0;
        }
        long result = 0;
        int sign = 1;
        int iterator = 0;
        // space
        while (str[iterator] == ' ') {
            ++iterator;
        }
        // sign
        if (str[iterator] == '-') {
            sign = -1;
            ++iterator;
        } else if (str[iterator] == '+') {
            sign = 1;
            ++iterator;
        }
        // int
        while (iterator != str.size()) {
            char cur = str[iterator];
            if (cur >= '0' && cur <= '9') {
                result *= 10;
                result += cur - '0';
                // overflow
                if (sign * result > INT_MAX) { return INT_MAX; }
                if (sign * result < INT_MIN) { return INT_MIN; }
            } else {
                break;
            }
            ++iterator;
        }
        return sign * result;
    }
};

// solution2: 22ms
class Solution {
public:
    int myAtoi(string str) {
        if (!str.size()) {
            return 0;
        }
        int result = 0;
        bool sign = true;
        int iterator = 0;
        // space
        while (str[iterator] == ' ') {
            ++iterator;
        }
        // sign
        if (str[iterator] == '-') {
            sign = false;
            ++iterator;
        } else if (str[iterator] == '+') {
            sign = true;
            ++iterator;
        }
        // int
        int overflow_bound = INT_MAX / 10;
        int overflow_reminder = INT_MAX % 10;
        while (iterator != str.size()) {
            char cur = str[iterator];
            if (cur >= '0' && cur <= '9') {
                // overflow
                if (result > overflow_bound || (result == overflow_bound && cur - '0' > overflow_reminder)) {
                    result = sign ? INT_MAX : INT_MIN;
                    return result;
                }
                result *= 10;
                result += cur - '0';
            } else {
                break;
            }
            ++iterator;
        }
        return sign ? result : -result;
    }
};