#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double curSum = 0.0;
        TreeNode *layerEnd = root, *nextEnd = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        int layerNodes = 0;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            layerNodes++;
            curSum += cur->val;
            if (cur->left) {
                q.push(cur->left);
                nextEnd = cur->left;
            }
            if (cur->right) {
                q.push(cur->right);
                nextEnd = cur->right;
            }
            if (cur == layerEnd) {
                layerEnd = nextEnd;
                res.push_back(curSum / layerNodes);
                layerNodes = 0;
                curSum = 0.0;
            }
        }
        return res;
    }
};