#include "ignored"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 递归
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        // 迭代
        // ListNode *head = new ListNode(-1);
        // ListNode *pre = head;
        // while (l1 != NULL && l2 != NULL) {
        //     if (l1->val <= l2->val) {
        //         pre->next = l1;
        //         l1 = l1->next;
        //     } else {
        //         pre->next = l2;
        //         l2 = l2->next;
        //     }
        //     pre = pre->next;
        // }
        // pre->next = l1 == NULL ? l2 : l1;
        // return head->next;
        
    }
};