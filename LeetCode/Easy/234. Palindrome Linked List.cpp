#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        ListNode *pre = head, *prePre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prePre;
            prePre = pre;
        }
        if (fast != nullptr) slow = slow->next;
        while (pre != nullptr && slow != nullptr) {
            if (pre->val != slow->val)
                return false;
            pre = pre->next;
            slow = slow->next;
        }
        // if necessary, the list should be restored.
        return true;
        
        // if (head == nullptr) return true;
        // deque<int> dq;
        // ListNode* p = head;
        // while (p != nullptr) {
        //     dq.push_back(p->val);
        //     p = p->next;
        // }
        // while (dq.size() > 1) {
        //     if (dq.front() == dq.back()) {
        //         dq.pop_front();
        //         dq.pop_back();
        //     } else return false;
        // }
        // return true;
    }
};