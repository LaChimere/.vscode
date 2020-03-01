#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isEqual(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return (root1->val == root2->val) && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (isEqual(cur, t)) return true;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return false;
        
        // if (!s && !t) return true;
        // if (!s || !t) return false;
        // if (s->val != t->val) return isSubtree(s->left, t) || isSubtree(s->right, t);
        // return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};