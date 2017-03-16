// solution1: 6ms
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        for (int y = height - 1; y != -1; --y) {
            for (int x = width - 1; x != -1; --x) {
                if (x == width - 1 && y == height - 1) {
                    continue;
                } else if (x == width - 1) {
                    grid[y][x] += grid[y + 1][x];
                } else if (y == height - 1) {
                    grid[y][x] += grid[y][x + 1];
                } else {
                    grid[y][x] += (grid[y][x + 1] < grid[y + 1][x] ? grid[y][x + 1] : grid[y + 1][x]);
                }
            }
        }
        return grid[0][0];
    }
private:
    int width, height;
};

// solution2: 9ms
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        std::vector<std::vector<int>> sum(height, std::vector<int>(width, MAX_SUM));
        return DP(grid, sum, 0, 0);
    }
private:
    const int MAX_SUM = 65535;
    int width, height;
    int DP(const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sum, int x, int y) {
        if (x < 0 || y < 0 || x >= width || y >= height) {
            return MAX_SUM;
        }
        // in cache
        int cur_sum = sum[y][x];
        if (cur_sum != MAX_SUM) {
            return cur_sum;
        }
        // not in cache, compute it
        int down = DP(grid, sum, x, y + 1);
        int right = DP(grid, sum, x + 1, y);
        if (down == right && down == MAX_SUM) {    // in this case, means we reach grid[height-1][width-1]
            return sum[y][x] = grid[y][x];
        } else {
            return sum[y][x] = grid[y][x] + (down < right ? down : right);
        }
    }
};
