// solution1: 19ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() >= 4) {
            std::sort(nums.begin(), nums.end());
            int length = nums.size();
            int last1 = nums[0] - 1;
            for (int i = 0; i != length - 3; ++i) {
                if (nums[i] == last1) {
                    continue;
                }
                last1 = nums[i];
                // avoid useless compute
                if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                    break;
                }
                int last2 = nums[i] - 1;
                for (int j = i + 1; j != length - 2; ++j) {
                    if (nums[j] == last2) {
                        continue;
                    }
                    last2 = nums[j];
                    // avoid useless compute
                    if (nums[j] + nums[j + 1] + nums[j + 2] > target - nums[i]) {
                        break;
                    }
                    int start = j + 1;
                    int end = length - 1;
                    int two_sum_target = target - nums[i] - nums[j];
                    while (start < end) {
                        if (nums[start] + nums[end] > two_sum_target) {
                            --end;
                        } else if (nums[start] + nums[end] < two_sum_target) {
                            ++start;
                        } else {
                            result.push_back({nums[i], nums[j], nums[start], nums[end]});
                            int last_end = nums[end];
                            while (start < end && nums[end] == last_end) {
                                --end;
                            }
                            int last_start = nums[start];
                            while (start < end && nums[start] == last_start) {
                                ++start;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

// solution2: tle
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         if (!nums.empty()) {
//             std::sort(nums.begin(), nums.end());
//             RecursiveFunc(nums, 0, 1, target);
//         }
//         return result;
//     }
// private:
//     std::vector<std::vector<int>> result;
//     std::vector<int> sum;

//     void RecursiveFunc(const std::vector<int>& nums, int it, int count, int target) {
//         if (count == 4) {
//             for (int i = it; i != nums.size(); ++i) {
//                 if (nums[i] == target) {
//                     sum.push_back(nums[i]);
//                     result.push_back(sum);
//                     sum.pop_back();
//                     break;
//                 }
//             }
//             return;
//         }
//         if (it == nums.size() - 1) {
//             return;
//         }
//         int last = nums[it] - 1;
//         for (int i = it; i != nums.size() - (4 - count); ++i) {
//             if (nums[i] != last) {
//                 sum.push_back(nums[i]);
//                 RecursiveFunc(nums, i + 1, count + 1, target - nums[i]);
//                 sum.pop_back();
//                 last = nums[i];
//             }
//         }
//     }
// };