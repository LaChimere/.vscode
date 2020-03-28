#include "tools"

class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26);
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode();
    }

    int insert(const string& word) {
        TrieNode* cur = root;
        bool isNew = false;
        for (int i = word.length() - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (cur->children[c] == nullptr) {
                isNew = true;
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        return isNew ? word.length() + 1 : 0;
    }
};

class Solution {
private:
    static bool cmp(const string& s1, const string& s2) {
        return s1.length() > s2.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int res = 0;
        Trie* trie = new Trie();
        for (string& word : words)
            res += trie->insert(word);
        return res;
    }
};