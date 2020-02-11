#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return max(left_height, right_height) + 1;

        // int nowMax = 0;
        // preOrder(root, 1, nowMax);
        // return nowMax;
    }
    // void preOrder(TreeNode* root, int depth, int& nowMax) {
    //     if (root == NULL) {
    //         if (nowMax < depth - 1) nowMax = depth - 1;
    //         return;
    //     }
    //     preOrder(root->left, depth + 1, nowMax);
    //     preOrder(root->right, depth + 1, nowMax);
    // }
};