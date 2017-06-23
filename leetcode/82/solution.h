/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 6ms, 168 cases
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = nullptr;
        while (fast->next) {
            if (fast->val == fast->next->val) {     // duplicates
                int last = fast->val;
                while (fast && fast->val == last) {
                    ListNode* temp = fast;
                    fast = fast->next;
                    delete temp;
                }
                // new head
                if (slow) {
                    slow->next = fast;
                } else {
                    head = fast;
                }
                // end of list
                if (!fast) {
                    break;
                }
            } else {
                slow = fast;
                fast = fast->next;
            }
        }

        return head;
    }
};