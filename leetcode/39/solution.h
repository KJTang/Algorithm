#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        tar_sum = target;
        nums = &candidates;
        for (int i = 0; i != nums->size(); ++i) {
            cur_sum = nums->at(i);
            arr.push_back(nums->at(i));
            if (cur_sum == tar_sum) {
                result.push_back(arr);
                break;
            } else if (cur_sum > tar_sum) {
                break;
            } else {
                RecursiveCombine(i);
            }
            arr.pop_back();
        }
        return result;
    }
private:
    int cur_sum;
    int tar_sum;
    std::vector<std::vector<int>> result;
    std::vector<int> arr;
    std::vector<int>* nums;

    bool RecursiveCombine(int last) {
        for (int i = last; i != nums->size(); ++i) {
            if (cur_sum + nums->at(i) == tar_sum) {
                arr.push_back(nums->at(i));
                result.push_back(arr);
                arr.pop_back();
                return true;
            } else if (cur_sum + nums->at(i) > tar_sum) {
                return false;
            } else {
                cur_sum += nums->at(i);
                arr.push_back(nums->at(i));
                RecursiveCombine(i);
                cur_sum -= nums->at(i);
                arr.pop_back();
            }
        }
        return false;
    }
};