#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void getMinDiff(TreeNode* root, TreeNode*& pre, int& nowMin) {
        if (!root) return;
        getMinDiff(root->left, pre, nowMin);
        if (pre) nowMin = min(nowMin, abs(root->val - pre->val));
        pre = root;
        getMinDiff(root->right, pre, nowMin);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        TreeNode* pre = nullptr;
        int nowMin = INT_MAX;
        getMinDiff(root, pre, nowMin);
        return nowMin;
        
        // if (!root) return INT_MAX;
        // int min1 = getMinimumDifference(root->left);
        // int min2 = getMinimumDifference(root->right);
        // int preMin = min1 < min2 ? min1 : min2;
        // TreeNode *nodeLeftRight = root->left, *nodeRightLeft = root->right;
        // while (nodeLeftRight && nodeLeftRight->right)
        //     nodeLeftRight = nodeLeftRight->right;
        // while (nodeRightLeft && nodeRightLeft->left)
        //     nodeRightLeft = nodeRightLeft->left;
        // int minLeft = INT_MAX, minRight = INT_MAX;
        // if (nodeLeftRight) minLeft = root->val - nodeLeftRight->val;
        // if (nodeRightLeft) minRight = nodeRightLeft->val - root->val;
        // int nowMin = minLeft < minRight ? minLeft : minRight;
        // return nowMin < preMin ? nowMin : preMin;
    }
};