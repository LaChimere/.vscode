#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // void changeVal(TreeNode* root, TreeNode*& pre) {
    //     if (!root) return;
    //     changeVal(root->right, pre);
    //     if (pre) root->val += pre->val;
    //     pre = root;
    //     changeVal(root->left, pre);
    // }

    // 反序中序Morris遍历
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left && succ->left != node)
            succ = succ->left;
        return succ;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        while (node) {
            /* 
             * if there's no right subtree, then we can visit this node and
             * continue traversing left.
             */
            if (!node->right) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            /*
             * if there's a right subtree, then there's at least one node that
             * has a greater value than the current one. therefore, we must 
             * traverse that subtree first.
             */
            else {
                TreeNode* succ = getSuccessor(node);
                // if the left subtree is nullptr, then we have never been here before.
                if (!succ->left) {
                    succ->left = node;
                    node = node->right;
                }
                /*
                 * if there's a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        return root;
    }

    // TreeNode* convertBST(TreeNode* root) {
    //     TreeNode *pre = nullptr;
    //     changeVal(root, pre);
    //     return root;
    // }
};