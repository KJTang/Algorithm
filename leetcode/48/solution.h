// solution1: 6ms
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix.size() - 1;
        while (end > start) {
            for (int i = start; i < end; ++i) {
                int temp = matrix[start][i];
                matrix[start][i] = matrix[end - (i - start)][start];
                matrix[end - (i - start)][start] = matrix[end][end - (i - start)];
                matrix[end][end - (i - start)] = matrix[i][end];
                matrix[i][end] = temp;
            }
            ++start;
            --end;
        }
    }
};

// solution2: 6ms
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (!matrix.empty()) {
            RecursiceRotate(matrix, 0, matrix.size() - 1);
        }
    }
private:
    void RecursiceRotate(std::vector<std::vector<int>>& matrix, int start, int end) {
        if (end <= start) {
            return;
        }
        for (int i = start; i < end; ++i) {
            int temp = matrix[start][i];
            matrix[start][i] = matrix[end - (i - start)][start];
            matrix[end - (i - start)][start] = matrix[end][end - (i - start)];
            matrix[end][end - (i - start)] = matrix[i][end];
            matrix[i][end] = temp;
        }
        RecursiceRotate(matrix, start + 1, end - 1);
    }
};
