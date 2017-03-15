// solution1: 9ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        width = board[0].size();
        for (int y = 0; y != height; ++y) {
            for (int x = 0; x != width; ++x) {
                if (DFS(board, word, x, y, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    int width, height;
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool DFS(std::vector<std::vector<char>>& board, const string& word, int x, int y, int p) {
        if (x < 0 || y < 0 || x >= width || y >= height || board[y][x] != word[p]) {
            return false;
        }
        if (p == word.size() - 1) {
            return true;
        }
        char last = board[y][x];
        board[y][x] = '\0';
        for (int i = 0; i != 4; ++i) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (DFS(board, word, next_x, next_y, p + 1)) {
                return true;
            }
        }
        board[y][x] = last;
        return false;
    }
};

// solution2: 139ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<bool>> flag(board.size() + 2, std::vector<bool>(board[0].size() + 2, true));
        ResetFlag(flag);
        for (int y = 0; y != board.size(); ++y) {
            for (int x = 0; x != board[0].size(); ++x) {
                if (board[y][x] == word[0]) {
                    flag[y+1][x+1] = true;
                    if (DFS(board, word, flag, x, y, 1)) {
                        return true;
                    }
                    ResetFlag(flag);
                }
            }
        }
        return false;
    }
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void ResetFlag(std::vector<std::vector<bool>>& flag) {
        for (int y = 1; y != flag.size() - 1; ++y) {
            for (int x = 1; x != flag[0].size() - 1; ++x) {
                flag[y][x] = false;
            }
        }
    }

    bool DFS(const std::vector<std::vector<char>>& board, const string& word, std::vector<std::vector<bool>>& flag, int x, int y, int p) {
        if (p == word.size()) {
            return true;
        }
        for (int i = 0; i != 4; ++i) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (!flag[next_y+1][next_x+1] && board[next_y][next_x] == word[p]) {
                flag[next_y+1][next_x+1] = true;    // mark
                if (DFS(board, word, flag, next_x, next_y, p + 1)) {
                    return true;
                }
                flag[next_y+1][next_x+1] = false;   // reset mark
            }
        }
        return false;
    }
};
