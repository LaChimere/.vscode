#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *pre = preHead;
        while (pre->next != NULL) {
            if (pre->next->val == val) pre->next = pre->next->next;
            else pre = pre->next;
        }
        return preHead->next;
    }
};