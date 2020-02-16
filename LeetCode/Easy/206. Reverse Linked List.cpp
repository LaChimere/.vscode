#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *pre = head, *p = pre->next;
        pre->next = nullptr;
        while (p != nullptr) {
            ListNode *q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        return pre;

        // 递归写法
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};