#include <string>
#include <vector>
#include <stringstream>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> result;
        std::stringstream ss;
        if (nums.size() == 0) {
            return result;
        }
        if (nums.size() == 1) {
            ss << nums[0];
            result.push_back(ss.str());
            return result;
        }

        int start = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] == nums[i-1] + 1) {
                continue;
            } else {
                ss << start;
                if (start != nums[i-1]) {
                    ss << "->" << nums[i-1];
                }
                result.push_back(ss.str());
                ss.str("");     // clear
                start = nums[i];
            }
        }
        // last range
        ss << start;
        if (start != nums.back()) {
            ss << "->" << nums.back();
        }
        result.push_back(ss.str());
        ss.str("");     // clear

        return result;
    }
};