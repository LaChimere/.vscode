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

class SolutionDP {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int len = nums.size();
        vector<int> left(len), right(len);
        left[0] = nums[0], right[len - 1] = nums[len - 1];

        for (int i = 1; i < len; i++) {
            if (i % k == 0) left[i] = nums[i];
            else left[i] = max(left[i - 1], nums[i]);

            int j = len - i - 1;
            if ((j + 1) % k == 0) right[j] = nums[j];
            else right[j] = max(right[j + 1], nums[j]);
        }

        vector<int> res;
        for (int i = 0; i < len - k + 1; i++)
            res.push_back(max(left[i + k - 1], right[i]));
        return res;
    }
};