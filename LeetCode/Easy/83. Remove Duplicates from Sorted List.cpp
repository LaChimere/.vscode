#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head != NULL) {
            ListNode *pre = head, *p = head->next;
            while (p != NULL) {
                if (pre->val == p->val) {
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                } else {
                    pre = p;
                    p = p->next;
                }
            }
        }
        return head;
    }
};