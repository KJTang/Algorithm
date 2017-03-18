class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        if (!matrix.size()) {
            return result;
        }
        result.reserve(matrix.size() * matrix[0].size());
        RecursiveFunc(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1, result);
        return result;
    }
private:
    void RecursiveFunc(const std::vector<std::vector<int>>& matrix, int x1, int y1, int x2, int y2, std::vector<int>& result) {
        if (x2 < x1 || y2 < y1) {
            return;
        }
        bool row = !(x2 - x1 == 0), column = !(y2 - y1 == 0);
        if (row && column) {
            for (int i = x1; i != x2 + 1; ++i) {
                result.push_back(matrix[y1][i]);
            }
            for (int i = y1 + 1; i != y2 + 1; ++i) {
                result.push_back(matrix[i][x2]);
            }
            for (int i = x2 - 1; i != x1 - 1; --i) {
                result.push_back(matrix[y2][i]);
            }
            for (int i = y2 - 1; i != y1; --i) {
                result.push_back(matrix[i][x1]);
            }
            RecursiveFunc(matrix, x1 + 1, y1 + 1, x2 - 1, y2 - 1, result);
        } else if (row) {
            for (int i = x1; i != x2 + 1; ++i) {
                result.push_back(matrix[y1][i]);
            }
        } else if (column) {
            for (int i = y1; i != y2 + 1; ++i) {
                result.push_back(matrix[i][x1]);
            }
        } else {
            result.push_back(matrix[y1][x1]);
        }
    }
};