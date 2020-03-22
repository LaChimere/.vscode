#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
        // int nodes = 0;
        // ListNode* p = head;
        // while (p) {nodes++; p = p->next;}
        // p = head;
        // for (int i = 0; i < nodes / 2; i++) p = p->next;
        // return p;
    }
};