#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) leaves.emplace_back(move(root->val));
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};