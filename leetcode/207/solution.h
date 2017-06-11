// solution: 26ms, 37 cases
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> graph;
        std::vector<bool> flag(numCourses, false);

        // build graph
        for (auto& prerequisite : prerequisites) {
            graph[prerequisite.first].push_back(prerequisite.second);
        }

        // travel graph
        for (int i = 0; i != numCourses; ++i) {
            if (!flag[i] && !DFS(i, flag, std::vector<bool>(numCourses, false), graph)) {
                return false;
            }
        }

        return true;
    }
private:
    bool DFS(int cur, std::vector<bool>& flag, std::vector<bool> path, const std::unordered_map<int, std::vector<int>>& graph) {
        if (flag[cur]) {    // if visited, it means has no cycle before, no need to detect any more
            return true;
        }
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


// solution: 149ms, 37 cases
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> graph;
        std::vector<bool> flag(numCourses, false);

        // build graph
        for (auto& prerequisite : prerequisites) {
            graph[prerequisite.first].push_back(prerequisite.second);
        }

        // travel graph
        for (int i = 0; i != numCourses; ++i) {
            if (!DFS(i, flag, graph)) {
                return false;
            }
        }

        return true;
    }
private:
    bool DFS(int cur, std::vector<bool>& flag, const std::unordered_map<int, std::vector<int>>& graph) {
        flag[cur] = true;   // visited
        auto it = graph.find(cur);
        if (it != graph.end()) {
            for (int i : it->second) {
                if (flag[i] || !DFS(i, flag, graph)) {
                    return false;
                }
            }
        }
        flag[cur] = false;
        return true;
    }
};