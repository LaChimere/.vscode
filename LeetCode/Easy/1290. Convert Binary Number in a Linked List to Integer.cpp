#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ans = (ans << 1) + p->val;
            p = p->next;
        }
        return ans;
    }
};