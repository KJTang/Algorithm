// solution1: 9ms
class Solution {
public:
    string multiply(string num1, string num2) {
        std::string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i != -1; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j != -1; --j) {
                int temp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            result[i] += carry;
        }
        size_t start = result.find_first_not_of('0');
        if (start == std::string::npos) {   // npos: max value of size_t
            return "0";
        } else {
            return result.substr(start);
        }
    }
};

// solution2: 16ms
class Solution {
public:
    string multiply(string num1, string num2) {
        std::string result("0");
        if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0')) {
            return result;
        }
        for (int i = num2.size() - 1; i != -1; --i) {
            AddString(result, MulChar(num1, num2[i] - '0', num2.size() - i - 1));
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
private:
    std::string MulChar(const std::string& a, int b, int zero) {
        if (b == 0) {
            return "0";
        }
        std::string result(zero, '0');
        int carry = 0;
        for (int i = a.size() - 1; i != -1; --i) {
            int cur = carry + (a[i] - '0') * b;
            result.push_back(cur % 10 + '0');
            carry = cur / 10;
        }
        while (carry != 0) {
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }
        return result;
    }

    void AddString(std::string& a_reverse, const std::string& b_reverse) {
        const std::string& shrt_str = a_reverse.size() < b_reverse.size() ? a_reverse : b_reverse;
        const std::string& long_str = a_reverse.size() < b_reverse.size() ? b_reverse : a_reverse;

        a_reverse.resize(long_str.size(), '0');     // extend a size
        int carry = 0;
        for (int i = 0; i != shrt_str.size(); ++i) {
            int cur = carry + (shrt_str[i] - '0') + (long_str[i] - '0');
            a_reverse[i] = cur % 10 + '0';
            carry = cur / 10;
        }
        for (int i = shrt_str.size(); i != long_str.size(); ++i) {
            int cur = carry + (long_str[i] - '0');
            a_reverse[i] = cur % 10 + '0';
            carry = cur / 10;
        }
        if (carry != 0) {
            a_reverse.push_back(carry + '0');
        }
    }
};