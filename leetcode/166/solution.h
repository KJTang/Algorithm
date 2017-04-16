// solution: 3ms, 35 cases
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        long long l_num = numerator;        // use long long in case of: -2147483648 / 1
        long long l_den = denominator;
        std::map<int, int> reminder;
        std::string num_str, dec_str;
        bool sign = true;
        if (l_num < 0) {
            l_num = -l_num;
            sign = !sign;
        }
        if (l_den < 0) {
            l_den = -l_den;
            sign = !sign;
        }
        long long num = l_num / l_den;
        long long rem = l_num % l_den;
        // sign
        if (!sign) {
            num_str.push_back('-');
        }
        // integer
        if (num == 0) {
            num_str.push_back('0');
        } else {
            std::string reverse_str;
            while (num != 0) {
                reverse_str.push_back(num % 10 + '0');
                num /= 10;
            }
            std::reverse(reverse_str.begin(), reverse_str.end());
            num_str += reverse_str;
        }
        // decimal
        if (rem == 0) {
            return num_str;
        } else {
            while (rem != 0) {
                auto it = reminder.find(rem);
                if (it != reminder.end()) {
                    dec_str.insert(it->second, 1, '(');
                    dec_str.push_back(')');
                    break;
                } else {
                    reminder.insert(std::make_pair(rem, dec_str.size()));
                }
                rem *= 10;
                num = rem / l_den;
                rem = rem % l_den;
                dec_str.push_back(num + '0');
            }
            return num_str + '.' + dec_str;
        }
    }
};