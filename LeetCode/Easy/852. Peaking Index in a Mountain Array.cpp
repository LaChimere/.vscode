#include "tools"
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) return mid;
            if (A[mid] < A[mid + 1]) left = mid;
            else right = mid;
        }
        return -1;
    }
};