// solution: 52ms, 66 cases, use BFS: 
// https://discuss.leetcode.com/topic/32534/c-bfs-short-clean-solution-with-explanation/2
// http://www.cnblogs.com/TonyYPZhang/p/5123058.html
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // Initialize the undirected graph
        std::vector<unordered_set<int>> adj(n);
        for (pair<int, int> p : edges) {
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }
        // Corner case
        std::vector<int> current;
        if (n == 1) {
            current.push_back(0);
            return current;
        }
        // Create first leaf layer
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i].size() == 1) {
                current.push_back(i);
            }
        }
        // BFS the graph
        while (true) {
            std::vector<int> next;
            for (int node : current) {
                for (int neighbor : adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) {
                        next.push_back(neighbor);
                    }
                }
            }
            if (next.empty()) {
                return current;
            }
            current = next;
        }
    }
};


// solution: 52ms, 66 cases, use DP(optimized)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // save edges into map
        height_.assign(n, std::map<int, int>());
        for (auto& edge : edges) {
            height_[edge.first].insert(std::make_pair(edge.second, -1));
            height_[edge.second].insert(std::make_pair(edge.first, -1));
        }

        // find nodes who has min height
        int min_height = INT_MAX;
        std::vector<int> result;
        for (int i = 0; i != n; ++i) {
            int cur_height = GetHeight(i, -1);
            if (cur_height == min_height) {
                result.push_back(i);
            } else if (cur_height < min_height) {
                min_height = cur_height;
                result.clear();
                result.push_back(i);
            }
        }

        return result;
    }
private:
    std::vector<std::map<int, int>> height_;

    int GetHeight(int node, int parent) {
        // cache hit
        if (parent != -1 && height_[parent][node] != -1) {
            return height_[parent][node];
        }

        // cache miss
        auto& linked_nodes = height_[node];
        int max_height = -1;
        for (auto& linked_node : linked_nodes) {
            if (linked_node.first != parent) {
                max_height = std::max(max_height, GetHeight(linked_node.first, node));
            }
        }

        // write cache
        if (parent != -1) {
            height_[parent][node] = max_height + 1;
        }

        return max_height + 1;
    }
};


// solution: tle, 58/66 cases, use DP
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // save edges into map
        for (auto& edge : edges) {
            edges_[edge.first].push_back(edge.second);
            edges_[edge.second].push_back(edge.first);
        }

        // find nodes who has min height
        int min_height = INT_MAX;
        std::vector<int> result;
        for (int i = 0; i != n; ++i) {
            int cur_height = GetHeight(i, -1);
            if (cur_height == min_height) {
                result.push_back(i);
            } else if (cur_height < min_height) {
                min_height = cur_height;
                result.clear();
                result.push_back(i);
            }
        }

        return result;
    }
private:
    std::map<int, std::vector<int>> edges_;

    int GetHeight(int node, int parent) {
        auto& linked_nodes = edges_[node];
        int max_height = -1;
        for (auto linked_node : linked_nodes) {
            if (linked_node != parent) {
                max_height = std::max(max_height, GetHeight(linked_node, node));
            }
        }
        return max_height + 1;
    }
};