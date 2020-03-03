#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // void getHash(TreeNode* root, unordered_set<int>& hash) {
    //     if (!root) return;
    //     getHash(root->left, hash);
    //     hash.insert(root->val);
    //     getHash(root->right, hash);
    // }
    
    bool findTarget(TreeNode* root, int k, unordered_set<int>& hash) {
        if (!root) return false;
        if (hash.count(k - root->val)) return true;
        hash.insert(root->val);
        return findTarget(root->left, k, hash) || findTarget(root->right, k, hash);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash;
        return findTarget(root, k, hash);
        
        // unordered_set<int> hash;
        // getHash(root, hash);
        // for (auto it = hash.begin(); it != hash.end(); it++) {
        //     int complement = k - *it;
        //     auto found = hash.find(complement);
        //     if (found != hash.end() && found != it)
        //         return true;
        // }
        // return false;
    }
};