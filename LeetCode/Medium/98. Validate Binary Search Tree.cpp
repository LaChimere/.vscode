#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isValidBST(TreeNode* root, long long low, long long high) {
        if (!root) return true;
        int mid = root->val;
        if (mid <= low || mid >= high) return false;
        return isValidBST(root->left, low, mid) && isValidBST(root->right, mid, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};