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
    unordered_map<int, int> id;
    
    TreeNode* buildTree(const vector<int>& preorder, int pStart, int pEnd,
                        const vector<int>& inorder, int inStart, int inEnd) {
        if (pStart == pEnd)
            return nullptr;
        
        int rootVal = preorder[pStart];
        auto* root = new TreeNode(rootVal);
        int leftSize = id[rootVal] - inStart;
        root->left = buildTree(preorder, pStart + 1, pStart + leftSize + 1,
                               inorder, inStart, id[rootVal]);
        root->right = buildTree(preorder, pStart + leftSize + 1, pEnd,
                                inorder, id[rootVal] + 1, inEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            id.emplace(inorder[i], i);
        
        int len = preorder.size();
        return buildTree(preorder, 0, len, inorder, 0, len);
    }
};