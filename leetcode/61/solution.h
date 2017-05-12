/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 13ms, 203 cases
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        // get old tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }
        // get new head & tail
        std::cout << k << " " << length << std::endl;
        k %= length;
        if (k) {
            k = length - k;
        }
        std::cout << "k: " << k << std::endl;

        ListNode* new_head = head;
        ListNode* new_tail = nullptr;
        while (k) {
            new_tail = new_head;
            new_head = new_head->next;
            --k;
        }
        // rotate
        if (new_tail) {
            tail->next = head;
            new_tail->next = nullptr;
            head = new_head;
        }

        return head;
    }
};