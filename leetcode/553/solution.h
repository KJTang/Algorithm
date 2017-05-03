// solution: 3ms, 93 cases, www.jianshu.com/p/f9e71aee128d
// explanation:
// for array: [a, b, c, d], 
// we know there must exist a 'a / b', like:
// [a / b / c / d] or [a / (b / c) / d] (=> [a * c / b / d]) or ...
// so we choose the result only has one division, which means:
// [a / (b / c / d)] (=> [a * c * d / b]) only has 'a / b'
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        } else if (nums.size() == 1) {
            return std::to_string(nums[0]);
        } else if (nums.size() == 2) {
            return std::to_string(nums[0]) + '/' + std::to_string(nums[1]);
        } else {
            string ret = std::to_string(nums[0]) + "/(" + std::to_string(nums[1]);
            for(int i=2; i<nums.size(); i++){
                ret += '/';
                ret += std::to_string(nums[i]);
            }
            ret += ')';
            return ret;
        }
    }
};