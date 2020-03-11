#include "tools"
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int total = 0;
        for (int num : A) total += num;
        if (total % 3) return false;
        int sum = 0, cnt = 0;
        for (int num : A) {
            sum += num;
            if (sum == total / 3) {cnt++; sum = 0;}
        }
        return cnt >= 3;
        
        // int total = 0;
        // for (int num : A) total += num;
        // if (total % 3) return false;
        // int left = 0, right = A.size() - 1;
        // int sum = total / 3, leftSum = A[left], rightSum = A[right];
        // while (left + 1 < right) {
        //     if (leftSum == sum && rightSum == sum) return true;
        //     if (leftSum != sum) leftSum += A[++left];
        //     if (rightSum != sum) rightSum += A[--right];
        // }
        // return false;
    }
};