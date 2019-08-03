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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        while (p != NULL && p->next != NULL) {
            q = q->next;
            p = p->next;
        }
        if (q == head && p == NULL) {
            head = q->next; // 内存泄漏
        } else {
            q->next = q->next->next;
        }
        return head;
    }
};