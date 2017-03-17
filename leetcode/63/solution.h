// solution1: 3ms
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        for (int y = height - 1; y >= 0; --y) {
            for (int x = width - 1; x >= 0; --x) {
                if (obstacleGrid[y][x] == 1) {
                    obstacleGrid[y][x] = 0;
                    continue;
                }
                if (x == width - 1 && y == height - 1) {
                    obstacleGrid[y][x] = -1;
                } else 
                if (x == width - 1) {
                    obstacleGrid[y][x] = obstacleGrid[y + 1][x];
                } else if (y == height - 1) {
                    obstacleGrid[y][x] = obstacleGrid[y][x + 1];
                } else {
                    obstacleGrid[y][x] = obstacleGrid[y + 1][x] + obstacleGrid[y][x + 1];
                }
            }
        }
        return -obstacleGrid[0][0];
    }
};

// solution2: time limit exceeded
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         if (!obstacleGrid.size()) {
//             return 0;
//         }
//         height = obstacleGrid.size();
//         width = obstacleGrid[0].size();
//         DFS(obstacleGrid, 0, 0);
//         return count;
//     }
// private:
//     long long count = 0;
//     int width, height;

//     void DFS(std::vector<std::vector<int>>& grid, int x, int y) {
//         if (x < 0 || y < 0 || x >= width || y >= height || grid[y][x] == 1) {
//             return;
//         }
//         if (x == width - 1 && y == height - 1) {
//             ++count;
//             return;
//         }
//         grid[y][x] = 1;
//         DFS(grid, x + 1, y);
//         DFS(grid, x, y + 1);
//         grid[y][x] = 0;
//         return;
//     }
// };