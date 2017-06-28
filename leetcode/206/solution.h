/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 9ms, 27 cases
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        Reverse(head);
        return new_head;
    }

private:
    ListNode* new_head = nullptr;

    ListNode* Reverse(ListNode* node) {
        if (!node) {
            return nullptr;
        }

        ListNode* reverse = Reverse(node->next);
        if (reverse) {
            reverse->next = node;
        } else {
            new_head = node;
        }
        node->next = nullptr;
        return node;
    }
};