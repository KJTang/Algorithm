#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        tar_sum = target;
        nums = &candidates;
        RecursiveCombine(0);
        return result;
    }
private:
    int cur_sum = 0;
    int tar_sum = 0;
    std::vector<std::vector<int>> result;
    std::vector<int> arr;
    std::vector<int>* nums;

    void RecursiveCombine(int last) {
        if (cur_sum == tar_sum) {
            result.push_back(arr);
            return;
        }
        for (int i = last; i != nums->size(); ++i) {
            if (cur_sum + nums->at(i) > tar_sum) {
                return;
            }
            if (i > last && nums->at(i) == nums->at(i-1)) {     // avoid same result
                continue;
            }
            cur_sum += nums->at(i);
            arr.push_back(nums->at(i));
            RecursiveCombine(i+1);
            cur_sum -= nums->at(i);
            arr.pop_back();
        }
        return;
    }
};