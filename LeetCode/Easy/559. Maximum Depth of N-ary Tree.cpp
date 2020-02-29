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
    int dfs(Node* root, int& nowMax) {
        if (!root) return 0;
        int nodeMax = 0;
        for (Node* child : root->children)
            nodeMax = max(nodeMax, dfs(child, nowMax));
        nodeMax += 1;
        if (nodeMax > nowMax) nowMax = nodeMax;
        return nodeMax;
    }
public:
    int maxDepth(Node* root) {
        int nowMax = 0;
        dfs(root, nowMax);
        return nowMax;
    }
};