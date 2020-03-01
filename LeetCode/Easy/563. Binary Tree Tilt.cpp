#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int findTilt(TreeNode* root, int& sum) {
        if (!root) return 0;
        int leftSum = findTilt(root->left, sum);
        int rightSum = findTilt(root->right, sum);
        int tilt = abs(leftSum - rightSum);
        sum += tilt;
        return root->val + leftSum + rightSum;
    }
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        findTilt(root, sum);
        return sum;
    }
};