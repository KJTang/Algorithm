// solution1: 26ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int min_height = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end) {
            min_height = std::min(height[start], height[end]);
            max_area = std::max(max_area, min_height * (end - start));
            while (height[start] <= min_height && start < end) {
                ++start;
            }
            while (height[end] <= min_height && start < end) {
                --end;
            }
        }
        return max_area;
    }
};

// solution2: tle
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max = 0;
//         int cur = 0;
//         int last_value = height.back();
//         for (int i = 0; i != height.size() - 1; ++i) {
//             last_value = height.back();
//             for (int j = height.size() - 1; j != i; --j) {
//                 if (height[j] < last_value) {
//                     ++last_value;
//                     continue;
//                 }
//                 cur = std::min(height[i], height[j]) * (j - i);
//                 max = std::max(cur, max);
//             }
//         }
//         return max;
//     }
// };

// solution3: tle
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max = 0;
//         int cur = 0;
//         for (int i = 0; i != height.size() - 1; ++i) {
//             for (int j = i + 1; j != height.size(); ++j) {
//                 cur = std::min(height[i], height[j]) * (j - i);
//                 max = std::max(cur, max);
//             }
//         }
//         return max;
//     }
// };