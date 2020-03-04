#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void preOrder(TreeNode* root, long& min1, long& min2) {
        if (!root) return;
        if (root->val < min1) {min2 = min1; min1 = root->val;}
        else if (root->val > min1 && root->val < min2) min2 = root->val;
        preOrder(root->left, min1, min2);
        preOrder(root->right, min1, min2);        
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        long min1 = 0xffffffff, min2 = 0xffffffff;
        preOrder(root, min1, min2);
        return min2;
    }
};