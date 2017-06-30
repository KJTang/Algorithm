/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 3ms, 44 cases
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // set before_reverse
        if (m >= 2) {
            before_reverse = head;
            for (int i = 2; i != m; ++i) {
                before_reverse = before_reverse->next;
            }
        }

        // reverse
        reverse_tail = Reverse((before_reverse ? before_reverse->next : head), n - m);

        // connect tail
        reverse_tail->next = after_reverse;

        // connect head
        if (!before_reverse) {
            head = reverse_head;
        } else {
            before_reverse->next = reverse_head;
        }

        return head;
    }

private:
    ListNode* before_reverse = nullptr;
    ListNode* after_reverse = nullptr;

    ListNode* reverse_head = nullptr;
    ListNode* reverse_tail = nullptr;

    ListNode* Reverse(ListNode* node, int n) {
        if (n == 0) {
            // set after_reverse
            after_reverse = node->next;
            return reverse_head = node;
        }
        ListNode* reverse = Reverse(node->next, n - 1);
        reverse->next = node;
        node->next = nullptr;
        return node;
    }
};