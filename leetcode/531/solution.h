#include <vector>

using std::vector;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int height = picture.size();
        int width = picture[0].size();

        std::vector<char> row = std::vector<char>(picture.size(), 0);
        std::vector<char> column = std::vector<char>(picture[0].size(), 0);

        for (int i = 0; i != height; ++i) {
            for (int j = 0; j != width; ++j) {
                if (picture[i][j] == 'B') {
                    ++row[i];
                    ++column[j];
                }
            }
        }
        int row_count = 0;
        int column_count = 0;
        for (int i = 0; i != height; ++i) {
            if (row[i] == 1) {
                ++row_count;
            }
        }
        for (int j = 0; j != width; ++j) {
            if (column[j] == 1) {
                ++column_count;
            }
        }
        return (row_count > column_count) ? column_count : row_count;
    }
};