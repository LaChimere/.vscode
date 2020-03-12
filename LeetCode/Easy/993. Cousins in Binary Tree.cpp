#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        vector<vector<int>> level(101, {-1, -1});
        q.push(root);
        level[root->val] = {-1, 0};
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                q.push(cur->left);
                level[cur->left->val] = {cur->val, level[cur->val][1] + 1};
            }
            if (cur->right) {
                q.push(cur->right);
                level[cur->right->val] = {cur->val, level[cur->val][1] + 1};
            }
        }
        return level[x][0] != level[y][0] && level[x][1] == level[y][1];
    }
};