#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    stack<int> s1, s2;
    
    void initStack(stack<int>& s, ListNode* head) {
        while (head) {
            s.push(head->val);
            head = head->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        initStack(s1, l1);
        initStack(s2, l2);
        int carry = 0;
        ListNode* head = new ListNode(-1);
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int digit = carry;
            digit += s1.empty() ? 0 : s1.top();
            digit += s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            ListNode* temp = new ListNode(digit % 10);
            temp->next = head->next;
            head->next = temp;
            carry = digit / 10;
        }
        return head->next;
    }
};