/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// solution: 49ms, 12 cases
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return nullptr;
        }

        RandomListNode* copy = new RandomListNode(head->label);
        std::map<int, RandomListNode*> node_map;
        node_map.insert(std::make_pair(head->label, copy));

        // copy next nodes
        RandomListNode* origin_node = head;
        RandomListNode* copy_node = copy;
        while (origin_node->next) {
            copy_node->next = new RandomListNode(origin_node->next->label);
            node_map.insert(std::make_pair(origin_node->next->label, copy_node->next));

            origin_node = origin_node->next;
            copy_node = copy_node->next;
        }

        // copy random nodes
        origin_node = head;
        copy_node = copy;
        while (origin_node) {
            if (origin_node->random) {
                copy_node->random = node_map[origin_node->random->label];
            }

            origin_node = origin_node->next;
            copy_node = copy_node->next;
        }

        return copy;
    }
};