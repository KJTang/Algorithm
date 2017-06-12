// solution: 26ms, 37 cases
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> graph;
        std::vector<bool> flag(numCourses, false);
        result_.reserve(numCourses);

        // build graph
        for (auto& prerequisite : prerequisites) {
            graph[prerequisite.first].push_back(prerequisite.second);
        }

        // travel graph
        for (int i = 0; i != numCourses; ++i) {
            if (!flag[i]) {
                if (!DFS(i, flag, std::vector<bool>(numCourses, false), graph)) {
                    return {};
                } else {
                    result_.insert(result_.end(), one_path_.rbegin(), one_path_.rend());
                    one_path_.clear();
                }
            }
        }

        return result_;
    }
private:
    std::vector<int> result_;
    std::vector<int> one_path_;

    bool DFS(int cur, std::vector<bool>& flag, std::vector<bool> path, const std::unordered_map<int, std::vector<int>>& graph) {
        if (flag[cur]) {    // if visited, it means has no cycle before, no need to detect any more
            return true;
        }
        one_path_.push_back(cur); // record path
        flag[cur] = true;   // visited
        path[cur] = true;
        auto it = graph.find(cur);
        if (it != graph.end()) {
            for (int i : it->second) {
                if (path[i] || !DFS(i, flag, path, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};