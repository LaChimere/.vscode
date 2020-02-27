#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inOrder(TreeNode* root, TreeNode*& pre, int& cnt, int& maxCnt, vector<int>& modes) {
        if (root == nullptr) return;
        inOrder(root->left, pre, cnt, maxCnt, modes);
        if (pre != nullptr)
            cnt = (root->val == pre->val) ? cnt + 1 : 1;
        if (cnt == maxCnt) modes.push_back(root->val);
        else if (cnt > maxCnt) {
            modes.clear();
            maxCnt = cnt;
            modes.push_back(root->val);
        }
        pre = root;
        inOrder(root->right, pre, cnt, maxCnt, modes);
    }
    
    // void inOrder(TreeNode* root, unordered_map<int, int>& hash) {
    //     if (root == nullptr) return;
    //     inOrder(root->left, hash);
    //     if (hash.find(root->val) != hash.end()) hash[root->val]++;
    //     else hash[root->val] = 1;
    //     inOrder(root->right, hash);
    // }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode *pre = nullptr;
        int cnt = 1, maxCnt = 0;
        inOrder(root, pre, cnt, maxCnt, modes);
        return modes;
        
        // unordered_map<int, int> hash;
        // inOrder(root, hash);
        // vector<int> modes;
        // int nowMax = 0;
        // for (auto it = hash.begin(); it != hash.end(); it++) {
        //     if (it->second == nowMax) modes.push_back(it->first);
        //     else if (it->second > nowMax) {
        //         nowMax = it->second;
        //         modes.clear();
        //         modes.push_back(it->first);
        //     }
                
        // }
        // return modes;
    }
};