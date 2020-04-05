#include <bits/stdc++.h>
using namespace std;

struct node {
    int key, val, freq;
    node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
private:
    int minFreq, capacity;
    unordered_map<int, list<node>::iterator> key_table;
    unordered_map<int, list<node>> freq_table;

public:
    LFUCache(int capacity) {
        this->minFreq = 0;
        this->capacity = capacity;
        this->key_table.clear();
        this->freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0)
            return -1;
        auto it = key_table.find(key);
        if (it == key_table.end())
            return -1;
        list<node>::iterator node_it = it->second;
        int val = node_it->val, freq = node_it->freq;
        freq_table[freq].erase(node_it);
        if (freq_table[freq].empty()) {
            freq_table.erase(freq);
            if (minFreq == freq)
                minFreq += 1;
        }
        freq_table[freq + 1].emplace_front(key, val, freq + 1);
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                node it2 = freq_table[minFreq].back();
                key_table.erase(it2.key);
                freq_table[minFreq].pop_back();
                if (freq_table[minFreq].empty()) {
                    freq_table.erase(minFreq);
                }
            }
            freq_table[1].emplace_front(key, value, 1);
            key_table[key] = freq_table[1].begin();
            minFreq = 1;
        } else {
            list<node>::iterator node_it = it->second;
            int freq = node_it->freq;
            freq_table[freq].erase(node_it);
            if (freq_table[freq].empty()) {
                freq_table.erase(freq);
                if (minFreq == freq)
                    minFreq += 1;
            }
            freq_table[freq + 1].emplace_front(key, value, freq + 1);
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */