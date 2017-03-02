#include <vector>

using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[i].size(); ++j) {
                board[i][j] = ComputeNextGenStat(board, i, j);
            }
        }
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[i].size(); ++j) {
                board[i][j] = (board[i][j] % 2 == 0) ? 1 : 0;
            }
        }
    }
private:
    static bool IsAlive(const vector<vector<int>>& board, int i, int j) {
        if (i < 0 || i >= board.size()) {
            return false;
        }
        if (j < 0 || j >= board[i].size()) {
            return false;
        }
        return (board[i][j] > 0);
    }

    static int ComputeNextGenStat(const vector<vector<int>>& board, int i, int j) {
        bool cur_stat = board[i][j] > 0;        // true for alive
        int count = cur_stat ? -1 : 0;
        for (int x = i-1; x <= i+1; ++x) {
            for (int y = j-1; y <= j+1; ++y) {
                if (IsAlive(board, x, y)) {
                    ++count;
                }
            }
        }

        int next_stat;
        if (cur_stat) {
            if (count == 2 || count == 3) {
                next_stat = 2;      // stay alive
            } else {
                next_stat = 1;      // alive to dead
            }
        } else {
            if (count == 3) {
                next_stat = 0;      // dead to alive
            } else {
                next_stat = -1;     // stay dead
            }
        }
        return next_stat;
    }
};