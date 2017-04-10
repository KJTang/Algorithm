// solution: 12ms, https://discuss.leetcode.com/topic/77916/java-10-lines-linear-time-complexity-o-n-with-explanation
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        std::vector<int> result(findNums.size(), -1);
        std::map<int, int> num_map;
        std::stack<int> num_stack;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            while (!num_stack.empty() && num_stack.top() < *it) {
                num_map[num_stack.top()] = *it;
                num_stack.pop();
            }
            num_stack.push(*it);
        }
        for (int i = 0; i != findNums.size(); ++i) {
            auto next = num_map.find(findNums[i]);
            if (next != num_map.end()) {
                result[i] = next->second;
            }
        }
        return result;
    }
};