#include <bits/stdc++.h>
using namespace std;

struct node {
    int cnt, time, key, value;
    node(int _cnt, int _time, int _key, int _value) :
        cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator< (const node& rhs) const {
        return cnt != rhs.cnt ? cnt < rhs.cnt : time < rhs.time;
    }
};

class LFUCache {
private:
    int capacity, time;
    unordered_map<int, node> key_table;
    set<node> s;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->time = 0;
        this->key_table.clear();
        this->s.clear();
    }
    
    int get(int key) {
        if (capacity == 0)
            return -1;
        auto it = key_table.find(key);
        if (it == key_table.end())
            return -1;
        node cache = it->second;
        s.erase(cache);
        cache.cnt++;
        cache.time = ++time;
        s.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                key_table.erase(s.begin()->key);
                s.erase(s.begin());
            }
            node cache(1, ++time, key, value);
            key_table.emplace(key, cache);
            s.insert(cache);
        } else {
            node cache = it->second;
            s.erase(cache);
            cache.cnt++;
            cache.time = ++time;
            cache.value = value;
            s.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */