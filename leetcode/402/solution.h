// solution: 3ms, 33 cases
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0) {
            return num;
        }
        if (num.size() <= k) {
            return "0";
        }

        std::vector<char> num_stack;
        int length = num.size();
        int i = 0, cnt = 0;

        while (i != length) {
            while (!num_stack.empty() && cnt != k && num[i] < num_stack.back()) {
                num_stack.pop_back();
                ++cnt;
            }
            num_stack.push_back(num[i++]);
        }

        while (!num_stack.empty() && cnt != k) {
            num_stack.pop_back();
            ++cnt;
        }

        // remove leading '0'
        auto it = num_stack.begin();
        while (it != num_stack.end() && (*it) == '0') {
            ++it;
        }
        return it == num_stack.end() ? "0" : std::string(it, num_stack.end());
    }
};