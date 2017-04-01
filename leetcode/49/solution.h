// solution1: 42ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::multiset<int>> map;

        for (int i = 0; i != strs.size(); ++i) {
            std::string temp = strs[i];
            std::sort(temp.begin(), temp.end());
            map[temp].insert(i);
        }
        for (auto it_i = map.begin(); it_i != map.end(); ++it_i) {
            result.push_back({});
            for (auto it_j = it_i->second.begin(); it_j != it_i->second.end(); ++it_j) {
                result.back().push_back(strs[*it_j]);
            }
        }

        return result;
    }
};

// solution2: tle, 99 / 100 test cases passed
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (int i = 0; i != strs.size(); ++i) {
            bool in_table = false;
            for (int j = 0; j != table.size(); ++j) {
                if (strs[i].size() == table[j].size() && SearchInTable(strs[i], table[j])) {
                    // save str in set already have
                    result[j].push_back(strs[i]);
                    in_table = true;
                    break;
                }
            }
            if (!in_table) {
                // create new set
                std::multiset<char> new_set;
                for (int k = 0; k != strs[i].size(); ++k) {
                    new_set.insert(strs[i][k]);
                }
                table.push_back(new_set);
                // save str
                std::vector<std::string> new_grp;
                new_grp.push_back(strs[i]);
                result.push_back(new_grp);
            }
        }
        return result;
    }
private:
    std::vector<std::vector<std::string>> result;
    std::vector<std::multiset<char>> table;

    bool SearchInTable(const std::string& str, std::multiset<char> set) {
        for (int i = 0; i != str.size(); ++i) {
            auto find_result = set.find(str[i]);
            if (find_result == set.end()) {
                return false;
            }
            set.erase(find_result);
        }
        return true;
    }
};
