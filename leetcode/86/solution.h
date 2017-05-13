/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 6ms, 166 cases
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* fast = head;
        ListNode* slow = nullptr;

        while (fast && fast->val < x) {
            slow = fast;
            fast = fast->next;
        }

        // no need to partition
        if (!fast) {
            return head;
        }
        // not partitioned yet
        while (fast->next) {
            if (fast->next->val < x) {
                if (!slow) {
                    // swap
                    ListNode* old_fast = fast->next;
                    fast->next = old_fast->next;
                    old_fast->next = head;
                    head = old_fast;
                    // inc
                    slow = head;
                } else {
                    // swap
                    ListNode* old_fast = fast->next;
                    fast->next = old_fast->next;
                    old_fast->next = slow->next;
                    slow->next = old_fast;
                    // inc
                    slow = slow->next;
                }
            } else {
                fast = fast->next;
            }
        }

        return head;
    }
};
