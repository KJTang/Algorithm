/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution: 52ms, 15 cases, time: O(nlogn), space: O(1), based on merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = GetMidNode(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

private:
    ListNode* GetMidNode(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = nullptr;           // cut of list by middle
        return node;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        if (!l2) { return l1; }

        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

// solution: 388ms, 15 cases, time: O(nlogn), space: O(1), based on quick sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* node = head;
        int count = 0;
        while (node) {
            ++count;
            node = node->next;
        }

        Sort(head, count);
        return head;
    }
private:
    void Sort(ListNode* node, int count) {
        if (count <= 1) {
            return;
        }
        ListNode* less_node = node;
        ListNode* more_node = node;
        int key = node->val;
        int less_cnt = 0;
        int more_cnt = 0;

        while (true) {
            // next less node
            while (less_cnt != count && less_node->val >= key) {
                ++less_cnt;
                less_node = less_node->next;
            }
            if (less_cnt == count) {
                break;
            }
            // swap
            std::swap(less_node->val, more_node->val);
            // next more node
            while (more_cnt != count && more_node->val < key) {
                ++more_cnt;
                more_node = more_node->next;
            }
            if (more_cnt == count) {
                break;
            }
        }

        // find divid node
        if (node->val == key) {
            Sort(node->next, count - 1);
        } else {
            ListNode* divid = node;
            int next_cnt = 0;
            while (divid->val < key) {
                ++next_cnt;
                divid = divid->next;
            }
            Sort(node, next_cnt);
            Sort(divid, count - next_cnt);
        }
    }
};