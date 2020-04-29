#include <bits/stdc++.h>
using namespace std;


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
    int get(int index);
    int length();
};


class Solution {
private:
    int biSearch(MountainArray& mountainArr, int left, int right, int target, int reverse) {
        target *= reverse;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int midVal = mountainArr.get(mid) * reverse;
            if (midVal == target)
                return mid;
            else if (midVal > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    int findMaxPos(MountainArray& mountainArr, int left, int right) {
        while (left < right) {
            int mid = (left + right) >> 1;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        int maxPos = findMaxPos(mountainArr, left, right);
        int ans = biSearch(mountainArr, left, maxPos, target, 1);
        if (ans != -1) return ans;
        return biSearch(mountainArr, maxPos + 1, right, target, -1);
    }
};