// solution: 29ms, 95 cases, https://discuss.leetcode.com/topic/67881/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation/2
// define the sequence: num1, num3, num2
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        std::stack<int> num_stack;  // stores candidates of num2
        int num2 = INT_MIN;         // stores max num2
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            if ((*it) < num2) {     // found
                return true;
            }
            while (!num_stack.empty() && (*it) > num_stack.top()) {
                num2 = num_stack.top();
                num_stack.pop();
            }
            num_stack.push((*it));
        }
        return false;
    }
};