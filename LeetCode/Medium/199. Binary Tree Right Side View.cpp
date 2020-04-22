#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void dfs(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level == res.size()) res.push_back(root->val);
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

class Solution2 {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0, curVal = root->val;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (level == cur.second)
                curVal = cur.first->val;
            else {
                res.push_back(curVal);
                curVal = cur.first->val;
                level = cur.second;
            }
            if (cur.first->left)
                q.push({cur.first->left, cur.second + 1});
            if (cur.first->right)
                q.push({cur.first->right, cur.second + 1});
        }
        res.push_back(curVal);
        return res;
    }
};