#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if (headA == NULL || headB == NULL) return NULL;
        // ListNode *p = headA, *q = headB;
        // while (p != q) {
        //     p = p == NULL ? headB : p->next;
        //     q = q == NULL ? headA : q->next;
        // }
        // return p;
        
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 0, lenB = 0;
        ListNode *p = headA, *q = headB;
        while (p != NULL) {lenA++; p = p->next;}
        while (q != NULL) {lenB++; q = q->next;}
        p = headA, q = headB;
        while (p != NULL && lenA > lenB) {p = p->next; lenA--;}
        while (q != NULL && lenB > lenA) {q = q->next; lenB--;}
        while (p != NULL && q != NULL) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};