/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

// solution: 26ms, 12 cases
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) : matrix_(matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        height_ = matrix_.size();
        width_ = matrix_[0].size();

        for (int i = 0; i != height_; ++i) {
            for (int j = 1; j != width_; ++j) {
                matrix_[i][j] += matrix_[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += matrix_[i][col2] - (col1 == 0 ? 0 : matrix_[i][col1 - 1]);
        }
        return sum;
    }
private:
    std::vector<std::vector<int>> matrix_;
    int height_, width_;
};
