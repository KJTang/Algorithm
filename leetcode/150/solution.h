// solution: 13ms, 20 cases
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;
        for (auto& token : tokens) {
            if (token.size() == 1) {
                switch (token[0]) {
                    case '+': {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a + b);
                        break;
                    }
                    case '-': {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a - b);
                        break;
                    }
                    case '*': {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a * b);
                        break;
                    }
                    case '/': {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a / b);
                        break;
                    }
                    default: {
                        nums.push(std::stoi(token));
                        break;
                    }
                }
            } else {
                nums.push(std::stoi(token));
            }
        }
        return nums.top();
    }
};