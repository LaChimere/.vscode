#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int paths(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        int ans = 0;
        if (root->val == sum) ans += 1;
        ans += paths(root->left, sum - root->val) + paths(root->right, sum - root->val);
        return ans;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return paths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        
        // unordered_map<TreeNode*, vector<int>> hash;
        // if (root == nullptr) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int cnt = 0;
        // while (!q.empty()) {
        //     TreeNode *cur = q.front();
        //     q.pop();
        //     hash[cur].push_back(cur->val);
        //     for (int i = 0; i < hash[cur].size(); i++)
        //         if (hash[cur][i] == sum) cnt++;
        //     if (cur->left != nullptr) {
        //         q.push(cur->left);
        //         for (int i = 0; i < hash[cur].size(); i++)
        //             hash[cur->left].push_back(hash[cur][i] + cur->left->val);
        //     }
        //     if (cur->right != nullptr) {
        //         q.push(cur->right);
        //         for (int i = 0; i < hash[cur].size(); i++)
        //             hash[cur->right].push_back(hash[cur][i] + cur->right->val);
        //     }
        // }
        // return cnt;
    }
};