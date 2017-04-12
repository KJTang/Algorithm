// solution: 0ms, similar to leetcode 31
#include <climits>
class Solution {
public:
    int nextGreaterElement(int n) {
        std::string num_str = TransToStr(n);
        // find top of increase-sequence
        int top = -1;
        int last = num_str[0] - 1;
        for (int i = 0; i != num_str.size(); ++i) {
            if (num_str[i] < last) {
                top = i;
                break;
            }
            last = num_str[i];
        }
        // find next
        if (top == -1) {
            return -1;
        } else {
            std::cout << n << " top: " << top << std::endl;
            int next_top = 0;
            for (int i = 0; i != top; ++i) {
                if (num_str[i] > num_str[top]) {
                    next_top = i;
                    break;
                }
            }
            std::cout << n << " num_str: " << num_str << std::endl;
            std::swap(num_str[next_top], num_str[top]);
            std::cout << n << " swp_str: " << num_str << std::endl;
            std::sort(num_str.begin(), num_str.begin() + top, std::greater<char>());
            std::cout << n << " srt_str: " << num_str << std::endl;
        }
        return TransToInt(num_str);
    }
private:
    // note: the string returned was rotated
    std::string TransToStr(int n) {
        if (n == 0) {
            return "0";
        }
        std::string str;
        while (n) {
            str.push_back(n % 10 + '0');
            n /= 10;
        }
        return str;
    }

    long long TransToInt(const std::string& str) {
        long long num = 0;
        for (int i = str.size() - 1; i != -1; --i) {
            num *= 10;
            num += str[i] - '0';
        }
        return num > INT_MAX ? -1 : num;
    }
};