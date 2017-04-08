// solution: 3ms, bookshadow.com/weblog/2017/04/03/leetcode-longest-uncommon-subsequence-ii/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // descending order
        std::sort(strs.begin(), strs.end(), [](const std::string& str1, const std::string& str2) {
            return str1.size() > str2.size();
        });
        // mark duplicate
        std::map<std::string, int> str_map;
        for (int i = 0; i != strs.size(); ++i) {
            ++str_map[strs[i]];
        }
        // find length
        for (int i = 0; i != strs.size(); ++i) {
            if (str_map[strs[i]] == 1) {
                bool is_single = true;      // mark if strings sizeof strs[i].size() only has 1
                for (int j = 0; j != strs.size() && strs[i].size() <= strs[j].size(); ++j) {
                    if (i != j) {
                        if (IsSubstrOf(strs[i], strs[j])) {
                            is_single = false;
                        }
                        break;
                    }
                }
                if (is_single) {
                    return strs[i].size();
                }
            }
        }
        return -1;
    }
private:
    bool IsSubstrOf(const std::string& str1, const std::string& str2) {
        if (str1.size() > str2.size()) {
            return false;
        }
        int i, j;
        for (i = 0, j = 0; i != str1.size() && j != str2.size(); ++j) {
            if (str1[i] == str2[j]) {
                ++i;
            }
        }
        return i == str1.size();
    }
};