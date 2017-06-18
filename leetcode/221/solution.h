// solution: 9ms, 69 cases, used DP, https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        height_ = matrix.size();
        width_ = matrix[0].size();

        std::vector<std::vector<int>> size(height_, std::vector<int>(width_, 0));
        // top
        for (int i = 0; i != width_; i++) {
            size[0][i] = matrix[0][i] - '0';
            cur_max_ = std::max(cur_max_, size[0][i]);
        }
        // left
        for (int j = 1; j < height_; j++) {
            size[j][0] = matrix[j][0] - '0';
            cur_max_ = std::max(cur_max_, size[j][0]);
        }
        // others
        for (int j = 1; j < height_; j++) {
            for (int i = 1; i < width_; i++) {
                if (matrix[j][i] == '1') {
                    size[j][i] = std::min(size[j - 1][i - 1], std::min(size[j - 1][i], size[j][i - 1])) + 1;
                    cur_max_ = std::max(cur_max_, size[j][i]);
                }
            }
        }
        return cur_max_ * cur_max_;
    }
private:
    int cur_max_ = 0;
    int width_ = 0;
    int height_ = 0;
};

// solution: 9ms, 68 cases
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        height_ = matrix.size();
        width_ = matrix[0].size();

        for (int j = 0; j < height_ - cur_max_; ++j) {
            for (int i = 0; i < width_ - cur_max_; ++i) {
                cur_max_ = std::max(cur_max_, MaxSquareAt(matrix, j, i));
            }
        }
        return cur_max_ * cur_max_;
    }
private:
    int cur_max_ = 0;
    int width_ = 0;
    int height_ = 0;

    int MaxSquareAt(const std::vector<std::vector<char>>& matrix, int y, int x) {
        int square_size = 0;
        int max_y = y + square_size;
        int max_x = x + square_size;
        while (max_y != height_ && max_x != width_) {
            // corner
            if (matrix[max_y][max_x] == '0') {
                return square_size;
            }
            // y-axis
            for (int j = y; j != max_y; ++j) {
                if (matrix[j][max_x] == '0') {
                    return square_size;
                }
            }
            // x-axis
            for (int i = x; i != max_x; ++i) {
                if (matrix[max_y][i] == '0') {
                    return square_size;
                }
            }
            ++square_size;
            ++max_y;
            ++max_x;
        }
        return square_size;
    }
};
