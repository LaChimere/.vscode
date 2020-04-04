#include <bits/stdc++.h>
using namespace std;

class Solution_DP {
public:
    int trap(vector<int>& height) {
        int sum = 0, len = height.size();
        vector<int> leftMax(len, 0), rightMax(len, 0);
        for (int i = 1; i < len; i++)
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        for (int i = len - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        for (int i = 1; i < len - 1; i++) {
            int minLevel = min(leftMax[i], rightMax[i]);
            if (minLevel > height[i])
                sum += minLevel - height[i];
        }
        return sum;
    }
};

class Solution_TwoPointers {
public:
    int trap(vector<int>& height) {
        int sum = 0, len = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 1, right = len - 2;
        for (int i = 1; i < len - 1; i++) {
            if (height[left - 1] < height[right + 1]) {
                leftMax = max(leftMax, height[left - 1]);
                int min = leftMax;
                if (min > height[left])
                    sum += min - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right + 1]);
                int min = rightMax;
                if (min > height[right])
                    sum += min - height[right];
                right--;
            }
        }
        return sum;
    }
};

class Solution_Stack {
public:
    int trap(vector<int>& height) {
        int sum = 0, len = height.size(), cur = 0;
        stack<int> st;
        while (cur < len) {
            while (!st.empty() && height[cur] > height[st.top()]) {
                int level = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int dis = cur - st.top() - 1;
                int minLevel = min(height[st.top()], height[cur]);
                sum += dis * (minLevel - level);
            }
            st.push(cur++);
        }
        return sum;
    }
};