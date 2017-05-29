// solution1: 372ms, 39 cases, BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int total = wordList.size();
        std::vector<std::vector<int>> change_list(total, std::vector<int>());
        std::vector<bool> visited(total, false);
        int end_word_id = -1;
        for (int i = 0; i < total; ++i) {
            if (end_word_id == -1 && wordList[i] == endWord) {
                end_word_id = i;
            }
            for (int j = i + 1; j < total; ++j) {
                if (IsDiff(wordList[i], wordList[j])) {
                    change_list[i].push_back(j);
                    change_list[j].push_back(i);
                }
            }
        }
        // endWord is not in the dict
        if (end_word_id == -1) {
            return 0;
        }
        // endWord is in the dict
        // BFS
        std::map<int, int> path;
        std::queue<int> visit_id;
        for (int i = 0; i < total; ++i) {
            if (IsDiff(wordList[i], beginWord)) {
                visit_id.push(i);
                visited[i] = true;
                path.insert(std::make_pair(i, -1));
            }
        }
        while (!visit_id.empty()) {
            int cur_id = visit_id.front();
            visit_id.pop();

            if (cur_id == end_word_id) {
                break;
            }

            for (int i = 0; i != change_list[cur_id].size(); ++i) {
                int next_id = change_list[cur_id][i];
                if (!visited[next_id]) {
                    visit_id.push(next_id);
                    visited[next_id] = true;
                    path.insert(std::make_pair(next_id, cur_id));
                }
            }
        }
        auto it = path.find(end_word_id);
        if (it == path.end()) {
            return 0;
        } else {
            int length = 2;
            while (it->second != -1) {
                it = path.find(it->second);
                ++length;
            }
            return length;
        }
    }
private:
    bool IsDiff(const std::string& str1, const std::string& str2) {
        int count = 0;
        for (int i = 0; i != str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                if (++count > 2) {
                    return false;
                }
            }
        }
        return count == 1;
    }
};

// solution2: 549ms, 39 cases, BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int total = wordList.size();
        std::vector<bool> visited(total, false);
        std::map<int, int> path;
        std::queue<int> visit_id;
        int end_word_id = -1;
        for (int i = 0; i < total; ++i) {
            if (end_word_id == -1 && wordList[i] == endWord) {
                end_word_id = i;
            }
            if (IsDiff(wordList[i], beginWord)) {
                visit_id.push(i);
                visited[i] = true;
                path.insert(std::make_pair(i, -1));
            }
        }
        // endWord is not in the dict
        if (end_word_id == -1) {
            return 0;
        }
        // endWord is in the dict
        while (!visit_id.empty()) {
            int cur_id = visit_id.front();
            visit_id.pop();

            if (cur_id == end_word_id) {
                break;
            }

            for (int next_id = 0; next_id < total; ++next_id) {
                if (!visited[next_id] && IsDiff(wordList[cur_id], wordList[next_id])) {
                    visit_id.push(next_id);
                    visited[next_id] = true;
                    path.insert(std::make_pair(next_id, cur_id));
                }
            }
        }
        auto it = path.find(end_word_id);
        if (it == path.end()) {
            return 0;
        } else {
            int length = 2;
            while (it->second != -1) {
                it = path.find(it->second);
                ++length;
            }
            return length;
        }
    }
private:
    bool IsDiff(const std::string& str1, const std::string& str2) {
        int count = 0;
        for (int i = 0; i != str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                if (++count > 2) {
                    return false;
                }
            }
        }
        return count == 1;
    }
};

// solution3: tle, DFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int total = wordList.size();
        std::vector<std::vector<int>> change_list(total, std::vector<int>());
        int end_word_id = -1;
        for (int i = 0; i < total; ++i) {
            if (end_word_id == -1 && wordList[i] == endWord) {
                end_word_id = i;
            }
            for (int j = i + 1; j < total; ++j) {
                if (IsDiff(wordList[i], wordList[j])) {
                    change_list[i].push_back(j);
                    change_list[j].push_back(i);
                }
            }
        }
        // endWord is not in the dict
        if (end_word_id == -1) {
            return 0;
        }
        // endWord is in the dict
        int result = INT_MAX;
        for (int i = 0; i < total; ++i) {
            if (IsDiff(wordList[i], beginWord)) {
                result_list_[i] = true;
                result = std::min(result, DFS(end_word_id, change_list, i));
                result_list_[i] = false;
            }
        }
        return result == INT_MAX ? 0 : result + 1;
    }
private:
    std::map<int, bool> result_list_;

    bool IsDiff(const std::string& str1, const std::string& str2) {
        int count = 0;
        for (int i = 0; i != str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                if (++count > 2) {
                    return false;
                }
            }
        }
        return count == 1;
    }

    int DFS(int end_word_id, const std::vector<std::vector<int>>& change_list, int cur_id) {
        if (end_word_id == cur_id) {
            return 1;
        }
        int count = INT_MAX;
        for (int i = 0; i != change_list[cur_id].size(); ++i) {
            int next_id = change_list[cur_id][i];
            if (!result_list_[next_id]) {
                result_list_[next_id] = true;
                count = std::min(count, DFS(end_word_id, change_list, next_id));
                result_list_[next_id] = false;
            }
        }
        return count == INT_MAX ? INT_MAX : count + 1;
    }
};