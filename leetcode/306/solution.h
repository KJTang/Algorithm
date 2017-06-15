// solution: 0ms, 40 cases
class Solution {
public:
    bool isAdditiveNumber(string num) {
        return RecursiveFunc(num, 0);
    }
private:
    std::vector<std::string> num_stk;

    bool RecursiveFunc(const std::string& num, int cur) {
        int last_len = num_stk.size() < 2 ? 1 : std::min(num_stk[num_stk.size() - 2].size(), num_stk[num_stk.size() - 1].size());
        if (cur + last_len > num.size()) {
            // print numbers
            // if (num_stk.size() >= 3) {
            //     std::cout << num << ": ";
            //     for (auto& num : num_stk) {
            //         std::cout << num << " ";
            //     }
            //     std::cout << std::endl;
            // }
            return num_stk.size() >= 3;
        }

        for (int i = last_len; i + cur <= num.size(); ++i) {
            if (IsAdditive(num.substr(cur, i))) {
                num_stk.push_back(num.substr(cur, i));
                if (RecursiveFunc(num, cur + i)) {
                    return true;
                }
                num_stk.pop_back();
            }
        }

        return false;
    }

    bool IsAdditive(const std::string& c) {
        if (c.size() > 1 && c[0] == '0') {                  // leading zero
            return false;
        }
        if (num_stk.size() < 2) {                           // stack hasn't enough nums
            return true;
        }

        std::string& a = num_stk[num_stk.size() - 2];
        std::string& b = num_stk[num_stk.size() - 1];

        if (c.size() < a.size() || c.size() < b.size()) {   // c less than a or b
            return false;
        }

        auto it_a = a.rbegin();
        auto it_b = b.rbegin();
        auto it_c = c.rbegin();
        int carry = 0;
        while (it_c != c.rend()) {
            carry += it_a == a.rend() ? 0 : (*it_a) - '0';
            carry += it_b == b.rend() ? 0 : (*it_b) - '0';

            if ((carry % 10) != (*it_c) - '0') {
                return false;
            }
            carry /= 10;

            if (it_a != a.rend()) { ++it_a; }
            if (it_b != b.rend()) { ++it_b; }
            ++it_c;
        }
        return carry == 0;
    }
};