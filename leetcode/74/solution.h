class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) {
            return false;
        }
        height = matrix.size();
        width = matrix[0].size();
        int start = 0, end = width * height - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int mid_num = GetNum(matrix, mid);
            std::cout << start << " " << end << " " << mid << " " << mid_num << std::endl;
            if (mid_num > target) {
                end = mid;
            } else if (mid_num < target) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
private:
    int width, height;

    int GetNum(const std::vector<std::vector<int>>& matrix, int p) {
        return matrix[p / width][p % width];
    }
};