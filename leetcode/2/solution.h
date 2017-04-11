/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            // add
            carry = l1->val + l2->val + carry;
            result->next = new ListNode(carry % 10);
            carry /= 10;
            // next
            l1 = l1->next;
            l2 = l2->next;
            result = result->next;
        }

        ListNode* l = l1 == nullptr ? l2 : l1;
        while (l != nullptr) {
            // add
            carry += l->val;
            result->next = new ListNode(carry % 10);
            carry /= 10;
            // next
            l = l->next;
            result = result->next;
        }

        if (carry) {
            result->next = new ListNode(carry);
        }
        result = head->next;
        delete head;
        return result;
    }
};