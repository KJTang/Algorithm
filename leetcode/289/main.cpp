#include <iostream>
#include <vector>

#include "solution.h"

// std::vector<std::vector<int>> board = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};
// std::vector<std::vector<int>> board = {{1,1},{1,0}};
std::vector<std::vector<int>> board = {{0,0,0,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0}};

void print(const std::vector<std::vector<int>>& board);

int main() {
    print(board);
    Solution s;
    s.gameOfLife(board);
    print(board);
    return 0;
}

void print(const std::vector<std::vector<int>>& board) {
    std::cout << "==================" << std::endl;
    for (int i = 0; i != board.size(); ++i) {
        for (int j = 0; j != board[i].size(); ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "==================" << std::endl;
}
