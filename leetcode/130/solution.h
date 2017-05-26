// solution: 9ms, 60 cases
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        height = board.size();
        width = board[0].size();

        // check borders
        for (int i = 0; i != width; ++i) {
            DFS(board, 0, i);           // up
            DFS(board, height - 1, i);  // down
        }
        for (int i = 0; i != height; ++i) {
            DFS(board, i, 0);           // left
            DFS(board, i, width - 1);   // right
        }

        for (int i = 0; i != height; ++i) {
            for (int j = 0; j != width; ++j) {
                if (board[i][j] != 'X') {
                    board[i][j] += offset;
                }
            }
        }
    }
private:
    int height, width;
    const int offset = 'X' - 'O';
    const int dir[4][2] = {
        {1, 0},     // up 
        {-1, 0},    // down
        {0, -1},    // left
        {0, 1}      // right
    };

    void DFS(std::vector<std::vector<char>>& board, int y, int x) {
        if (y < 0 || y >= height || x < 0 || x >= width || board[y][x] != 'O') {
            return;
        }
        board[y][x] -= offset;
        for (int i = 0; i != 4; ++i) {
            DFS(board, y + dir[i][0], x + dir[i][1]);
        }
    }
};