#include "tools"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void treeToStr(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val);
        if (!root->left && !root->right) {
            treeToStr(root->left, s);
            treeToStr(root->right, s);
        } else if (root->left && !root->right) {
            s += "(";
            treeToStr(root->left, s);
            s += ")";
            treeToStr(root->right, s);
        } else {
            s += "(";
            treeToStr(root->left, s);
            s += ")(";
            treeToStr(root->right, s);
            s += ")";
        }
    }
public:
    string tree2str(TreeNode* t) {
        string res;
        treeToStr(t, res);
        return res;
    }
};