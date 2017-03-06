#include <vector>

using std::vector;

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int height = picture.size();
        int width = picture[0].size();

        std::vector<char> row = std::vector<char>(picture.size(), 0);
        std::vector<char> column = std::vector<char>(picture[0].size(), 0);
        std::map<int, std::vector<int>> row_map;
        std::vector<int> row_info;

        for (int i = 0; i != height; ++i) {
            row_info.clear();
            for (int j = 0; j != width; ++j) {
                if (picture[i][j] == 'B') {
                    ++row[i];
                    ++column[j];
                    row_info.push_back(j);
                }
            }
            row_map.insert(std::make_pair(i, row_info));
        }

        int count = 0;
        for (int i = 0; i != height; ++i) {
            if (row[i] == N) {
                for (int j = 0; j != width; ++j) {
                    if (column[j] == N) {
                        if (N > 1) {
                            auto& cur_row_info = row_map[i];
                            int other_count = 0;
                            for (int k = 0; k != height; ++k) {
                                if (picture[k][j] == 'B' && k != i) {
                                    if (cur_row_info == row_map[k]) {
                                        ++other_count;
                                    } else {
                                        break;
                                    }
                                }
                            }
                            if (other_count == N - 1) {
                                ++count;
                            }
                        } else if (picture[i][j] == 'B') {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};