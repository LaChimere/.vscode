#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        auto *p1 = l1, *p2 = l2;
        int t = 0;
        while (p1 || p2 || t != 0) {
            if (p1) {
                t += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                t += p2->val;
                p2 = p2->next;
            }
            ListNode* s = new ListNode(t % 10);
            tail->next = s;
            tail = s;
            t /= 10;
        }
        return head->next;
    }
};