#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            TreeNode* p = cur.first;
            int level = cur.second;
            
            if (level >= res.size())
                res.push_back({p->val});
            else
                res.back().push_back(p->val);
            
            if (p->left)
                q.emplace(p->left, level + 1);
            if (p->right)
                q.emplace(p->right, level + 1);
        }
        
        return res;
    }
};