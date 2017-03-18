class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return {};
        }
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        RecursiveFunc(matrix, 0, n - 1);
        return matrix;
    }
private:
    int inc_num = 1;
    void RecursiveFunc(std::vector<std::vector<int>>& matrix, int start, int end) {
        if (end < start) {
            return;
        }
        if (end == start) {
            matrix[start][start] = inc_num;
            return;
        }
        // top
        for (int i = start; i != end; ++i) {
            matrix[start][i] = inc_num;
            ++inc_num;
        }
        // right
        for (int i = start; i != end; ++i) {
            matrix[i][end] = inc_num;
            ++inc_num;
        }
        // down
        for (int i = end; i != start; --i) {
            matrix[end][i] = inc_num;
            ++inc_num;
        }
        // left
        for (int i = end; i != start; --i) {
            matrix[i][start] = inc_num;
            ++inc_num;
        }
        RecursiveFunc(matrix, start + 1, end - 1);
    }
};