#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode* head, ListNode* stop)
    {
        if (head == stop || head->next == stop)
            return head;
        
        ListNode* cur = reverseList(head->next, stop);
        head->next->next = head;
        head->next = stop;
        
        return cur;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0, update = 0;
        ListNode* p = head;
        ListNode* s = head;
        ListNode* nhead = head;
        ListNode* preTail = nullptr;
        
        while (p) {
            while (s && cnt < k) {
                s = s->next;
                cnt++;
            }
            if (cnt < k)
                break;
            update++;
            ListNode* t = reverseList(p, s);
            if (update == 1)
                nhead = t;
            if (preTail)
                preTail->next = t;
            
            preTail = p;
            p = s;
            cnt = 0;
        }
        
        return nhead;
    }
};