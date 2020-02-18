#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ret = root;
        while (ret != nullptr) {
            if (p->val > ret->val && q->val > ret->val)
                ret = ret->right;
            else if (p->val < ret->val && q->val < ret->val)
                ret = ret->left;
            else return ret;
        }
        return nullptr;
        
        // if (root == nullptr) return nullptr;
        // queue<TreeNode*> q1, q2;
        // TreeNode *s1 = root, *s2 = root;
        // q1.push(s1);
        // q2.push(s2);
        // while (s1 != p) {
        //     if (p->val < s1->val) s1 = s1->left;
        //     else s1 = s1->right;
        //     q1.push(s1);
        // }
        // while (s2 != q) {
        //     if (q->val < s2->val) s2 = s2->left;
        //     else s2 = s2->right;
        //     q2.push(s2);
        // }
        // TreeNode *ret = nullptr;
        // while (!q1.empty() && !q2.empty() && q1.front() == q2.front()) {
        //     ret = q1.front();
        //     q1.pop();
        //     q2.pop();
        // }
        // return ret;
    }
};