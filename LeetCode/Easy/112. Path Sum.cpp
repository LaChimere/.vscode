#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 层序遍历/BFS
        if (root == NULL) return false;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if (cur.first->left == NULL && cur.first->right == NULL && cur.second == sum)
                return true;
            if (cur.first->left != NULL)
                q.push(make_pair(cur.first->left, cur.second + cur.first->left->val));
            if (cur.first->right != NULL)
                q.push(make_pair(cur.first->right, cur.second + cur.first->right->val));
        }
        return false;

        // 递归/DFS
        // if (root == NULL) return false;
        // sum -= root->val;
        // if (root->left == NULL && root->right == NULL) return sum == 0;
        // return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};