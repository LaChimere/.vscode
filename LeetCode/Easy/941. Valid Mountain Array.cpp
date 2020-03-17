#include "tools"
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if (len < 3) return false;
        int left = 0, right = len - 1;
        while (left < len - 2 && A[left] < A[left + 1]) left++;
        while (right > 1 && A[right] < A[right - 1]) right--;
        return left == right;
        
        
        // int maxIndex = 0;
        // for (int i = 1; i < len; i++)
        //     maxIndex = A[i] > A[maxIndex] ? i : maxIndex;
        // if (maxIndex == 0 || maxIndex == len - 1) return false;
        // for (int i = 1; i <= maxIndex; i++)
        //     if (A[i] <= A[i - 1]) return false;
        // for (int i = maxIndex + 1; i < len; i++)
        //     if (A[i] >= A[i - 1]) return false;
        // return true;
    }
};