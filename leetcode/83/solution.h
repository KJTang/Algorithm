/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 13ms, 164 cases
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        int cur_num = head->val;
        while (fast) {
            if (fast->val == cur_num) {
                slow->next = fast->next;
                delete fast;
                fast = slow->next;
            } else {
                slow = slow->next;
                fast = fast->next;
                cur_num = slow->val;
            }
        }
        return head;
    }
};