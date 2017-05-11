/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 6ms, 207 cases
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* last = nullptr;

        // save last n node
        while (n != 0) {
            cur = cur->next;
            --n;
        }
        last = head;

        // remove nth node
        if (!cur) {     // nth node is head
            head = last->next;
            delete last;
        } else {        // nth node is not head
            while (cur->next) {
                last = last->next;
                cur = cur->next;
            }
            ListNode* node_to_rm = last->next;
            last->next = node_to_rm->next;
            delete node_to_rm;
        }

        return head;
    }
};