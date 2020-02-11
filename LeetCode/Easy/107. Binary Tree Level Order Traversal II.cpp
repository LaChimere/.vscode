#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> curLevel;
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode *curNode = q.front();
                q.pop();
                curLevel.push_back(curNode->val);
                if (curNode->left != NULL) q.push(curNode->left);
                if (curNode->right != NULL) q.push(curNode->right);
            }
            v.insert(v.begin(), curLevel);
        }
        return v;
    }
};