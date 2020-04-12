#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    queue<int> q;
    deque<int> maxVal;
    
    int maxValue() {
        if (q.empty())
            return INT_MIN;
        return maxVal.front();
    }
    
    void pushQueue(int value) {
        q.push(value);
        while (!maxVal.empty() && maxVal.back() < value)
            maxVal.pop_back();
        maxVal.push_back(value);
    }
    
    int popQueue() {
        if (q.empty())
            return INT_MIN;
        int front = q.front();
        q.pop();
        if (front == maxVal.front())
            maxVal.pop_front();
        return front;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (const int& num : nums) {
            pushQueue(num);
            while(q.size() > k) popQueue();
            if (q.size() == k) res.push_back(maxValue());
        }
        return res;
    }
};