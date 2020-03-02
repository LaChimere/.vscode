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
    void postorder(Node* root, vector<int>& list) {
        if (!root) return;
        for (Node* child : root->children) postorder(child, list);
        list.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> list;
        postorder(root, list);
        return list;
    }
};