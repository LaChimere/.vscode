#include "tools"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void preorder(Node* root, vector<int>& list) {
        if (!root) return;
        list.push_back(root->val);
        for (Node* child : root->children) preorder(child, list);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> list;
        preorder(root, list);
        return list;
    }
};