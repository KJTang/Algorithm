/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 62ms, 13 cases
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* node = head;
        std::stack<ListNode*> node_stack;
        int length = 0;
        while (node) {
            node_stack.push(node);
            node = node->next;
            length++;
        }

        // no need to change
        if (length <= 2) {
            return;
        }

        int mid = length / 2;
        int cur = 0;
        while (cur != mid) {
            ListNode* after = head->next;
            ListNode* insert = node_stack.top();
            node_stack.pop();

            head->next = insert;
            insert->next = after;

            ++cur;
            head = after;
        }
        head->next = nullptr;
    }
};