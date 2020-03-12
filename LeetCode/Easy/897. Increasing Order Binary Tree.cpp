#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // void inOrder(TreeNode* root, queue<TreeNode*>& q) {
    //     if (!root) return;
    //     inOrder(root->left, q);
    //     q.push(root);
    //     inOrder(root->right, q);
    // }
    
    void inOrder(TreeNode* root, TreeNode*& cur) {
        if (!root) return;
        inOrder(root->left, cur);
        root->left = nullptr;
        cur->right = root;
        cur = root;
        inOrder(root->right, cur);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* preRoot = new TreeNode(-1);
        TreeNode* cur = preRoot;
        inOrder(root, cur);
        return preRoot->right;
        
        // queue<TreeNode*> nodes;
        // inOrder(root, nodes);
        // root = nodes.front();
        // nodes.pop();
        // TreeNode* pre = root;
        // while (!nodes.empty()) {
        //     TreeNode* cur = nodes.front();
        //     nodes.pop();
        //     pre->left = nullptr;
        //     pre->right = cur;
        //     pre = cur;
        // }
        // pre->left = pre->right = nullptr;
        // return root;
    }
};