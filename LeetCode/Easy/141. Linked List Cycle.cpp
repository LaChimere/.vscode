#include "tools"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // using fast and slow pointers, time complexity: O(n), space complexity: O(1)
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        while (fast != slow) {
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
        
        // using Hash Table, time complexity: O(n), space complexity: O(n)
        // if (head == NULL) return false;
        // unordered_set<ListNode*> isVisited;
        // ListNode *p = head;
        // isVisited.insert(p);
        // while (p->next != NULL) {
        //     p = p->next;
        //     isVisited.insert(p);
        //     if (isVisited.find(p->next) != isVisited.end())
        //         break;
        // }
        // if (p->next == NULL) return false;
        // else return true;
    }
};