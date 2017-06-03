/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode*> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// solution: 32ms, 12 cases
#include <vector>
#include <map>
#include <queue>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct MyNode {
    UndirectedGraphNode* clone;
    UndirectedGraphNode* origin;
    MyNode(UndirectedGraphNode* c, UndirectedGraphNode* o) : clone(c), origin(o) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node) {
            return nullptr;
        }

        std::map<int, MyNode> node_map;
        std::queue<UndirectedGraphNode*> node_queue;

        UndirectedGraphNode* clone_node = new UndirectedGraphNode(node->label);
        node_map.insert(std::make_pair(node->label, MyNode(clone_node, node)));
        node_queue.push(node);

        while (!node_queue.empty()) {
            UndirectedGraphNode* cur = node_queue.front();
            node_queue.pop();

            for (auto neighbor = cur->neighbors.begin(); neighbor != cur->neighbors.end(); ++neighbor) {
                auto it = node_map.find((*neighbor)->label);
                if (it == node_map.end()) {
                    node_map.insert(std::make_pair((*neighbor)->label, MyNode(new UndirectedGraphNode((*neighbor)->label), (*neighbor))));
                    node_queue.push((*neighbor));
                }
            }
        }

        for (auto node = node_map.begin(); node != node_map.end(); ++node) {
            auto clone = node->second.clone;
            auto origin = node->second.origin;
            for (auto neighbor = origin->neighbors.begin(); neighbor != origin->neighbors.end(); ++neighbor) {
                auto it = node_map.find((*neighbor)->label);
                clone->neighbors.push_back(it->second.clone);
            }
        }

        return clone_node;
    }
};