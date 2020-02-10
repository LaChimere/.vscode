#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 递归
        // if (p == NULL && q == NULL) return true;
        // if (p == NULL || q == NULL) return false;
        // if (p->val != q->val) return false;
        // return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        queue<TreeNode*> qu_p, qu_q;
        qu_p.push(p);
        qu_q.push(q);
        while (!qu_p.empty() && !qu_p.empty()) {
            TreeNode *frontP = qu_p.front();
            TreeNode *frontQ = qu_q.front();
            qu_p.pop();
            qu_q.pop();
            if (frontP != NULL && frontQ != NULL && frontP->val == frontQ->val) {
                qu_p.push(frontP->left);
                qu_p.push(frontP->right);
                qu_q.push(frontQ->left);
                qu_q.push(frontQ->right);
            } else if (frontP == NULL && frontQ == NULL) {
                continue;
            } else return false;
        }
        if (qu_p.empty() && qu_q.empty())
            return true;
        else return false;
    }
};