class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return;
        }
        int height = matrix.size();
        int width = matrix[0].size();
        // mark
        bool first_row = false, first_column = false;
        for (int i = 0; i != height; ++i) { // detect if first column has 0
            if (matrix[i][0] == 0) {
                first_column = true;
                break;
            }
        }
        for (int j = 0; j != width; ++j) {  // detect if first row has 0
            if (matrix[0][j] == 0) {
                first_row = true;
                break;
            }
        }
        for (int i = 1; i < height; ++i) {  // mark 0's column & row number, save it in first column and first row
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set zero
        for (int i = 1; i < height; ++i) {
            if (matrix[i][0] == 0) {
                for (int k = 0; k != width; ++k) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int j = 1; j < width; ++j) {
            if (matrix[0][j] == 0) {
                for (int k = 0; k != height; ++k) {
                    matrix[k][j] = 0;
                }
            }
        }
        if (first_column) {
            for (int i = 0; i != height; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (first_row) {
            for (int j = 0; j != width; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
