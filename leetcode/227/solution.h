// solution1: 19ms
class Solution {
public:
    int calculate(string s) {
        s.push_back(' ');   // ending
        std::vector<int> num_stack;
        std::vector<char> op_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            switch (s[i]) {
                case '+': case '-': case '*': case '/': {
                    while (!op_stack.empty() && prior[op_stack.back()] >= prior[s[i]]) {
                        int b = num_stack.back();
                        num_stack.pop_back();
                        int a = num_stack.back();
                        num_stack.pop_back();
                        num_stack.push_back(Cal(a, b, op_stack.back()));
                        op_stack.pop_back();
                    }
                    op_stack.push_back(s[i]);
                    break;
                }
                default: {
                    int num = 0;
                    while (isdigit(s[i])) {
                        num *= 10;
                        num += s[i] - '0';
                        ++i;
                    }
                    --i;
                    num_stack.push_back(num);
                    break;
                }
            }
        }
        while (!op_stack.empty()) {
            int b = num_stack.back();
            num_stack.pop_back();
            int a = num_stack.back();
            num_stack.pop_back();
            num_stack.push_back(Cal(a, b, op_stack.back()));
            op_stack.pop_back();
        }
        return num_stack.back();
    }
private:
    std::map<char, int> prior = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
    inline int Cal(int a, int b, char op) {
        switch (op) {
            case '+': {
                return a + b;
            }
            case '-': {
                return a - b;
            }
            case '*': {
                return a * b;
            }
            case '/': {
                return a / b;
            }
        }
        return 0;
    }
};

// solution2: 29ms, intersting solution: https://discuss.leetcode.com/topic/16807/17-lines-c-easy-20-ms/9
class Solution {
public:
    int calculate(string s) {
        std::stringstream ss('+' + s + '+');
        long long total = 0, term = 0, factor = 0;
        char op;
        while (ss >> op) {
            if (op == '+' || op == '-') {
                total += term;
                ss >> term;
                term *= (op == '+' ? 1 : -1);
            } else {
                ss >> factor;
                if (op == '*') {
                    term *= factor;
                } else {
                    term /= factor;
                }
            }
        }
        return total;
    }
};