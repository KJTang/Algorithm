class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        std::vector<int> stroage(triangle.size() + 1, 0);
        for (int i = triangle.size() - 1; i != -1; --i) {
            for (int j = 0; j != i + 1; ++j) {
                stroage[j] = stroage[j] < stroage[j+1] ? stroage[j] + triangle[i][j] : stroage[j+1] + triangle[i][j];
            }
        }
        return stroage[0];
    }
};