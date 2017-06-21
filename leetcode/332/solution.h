// warning: I think this problem has inaccurate description, 
//          the "correct" answer can't match the description

// solution: 16ms, 80 cases, https://discuss.leetcode.com/topic/36721/short-c-dfs-iterative-44ms-solution-with-explanation-no-recursive-calls-no-backtracking
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Each node (airport) contains a set of outgoing edges (destination).
        unordered_map<string, multiset<string>> graph;
        // We are always appending the deepest node to the itinerary, 
        // so will need to reverse the itinerary in the end.
        vector<string> itinerary;
        if (tickets.size() == 0){
            return itinerary;
        }
        // Construct the node and assign outgoing edges
        for (pair<string, string> eachTicket : tickets){
            graph[eachTicket.first].insert(eachTicket.second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()){
            string topAirport = dfs.top();
            if (graph[topAirport].empty()){
                // If there is no more outgoing edges, append to itinerary
                // Two cases: 
                // 1. If it searchs the terminal end first, it will simply get
                //    added to the itinerary first as it should, and the proper route
                //    will still be traversed since its entry is still on the stack.
                // 2. If it search the proper route first, the dead end route will also
                //    get added to the itinerary first.
                itinerary.push_back(topAirport);
                dfs.pop();
            }
            else {
                // Otherwise push the outgoing edge to the dfs stack and 
                // remove it from the node.
                dfs.push(*(graph[topAirport].begin()));
                graph[topAirport].erase(graph[topAirport].begin());
            }
        }
        // Reverse the itinerary.
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

// solution: wrong answer
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // build graph
        for (auto& ticket : tickets) {
            tickets_[ticket.first].insert(std::make_pair(ticket.second, false));
        }

        // dfs the graph
        DFS("JFK");

        return itinerary_;
    }
private:
    std::map<std::string, std::map<std::string, bool>> tickets_;
    std::vector<std::string> itinerary_;

    void DFS(const std::string& cur) {
        itinerary_.push_back(cur);
        for (auto& next : tickets_[cur]) {
            if (!next.second) {     // unvisited
                next.second = true; // mark as visited
                DFS(next.first);
            }
        }
    }
};