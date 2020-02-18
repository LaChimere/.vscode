#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        constructPaths(root, "", paths);
        return paths;
    }
    
    void constructPaths(TreeNode* root, string path, vector<string>& paths) {
        if (root) {
            path += to_string(root->val);
            if (!root->left && !root->right)
                paths.push_back(path);
            else {
                path += "->";
                constructPaths(root->left, path, paths);
                constructPaths(root->right, path, paths);
            }
        }
    }
};