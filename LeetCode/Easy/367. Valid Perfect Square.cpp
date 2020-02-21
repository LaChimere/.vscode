#include "tools"
class Solution {
public:
    bool isPerfectSquare(int num) {
        // Newton's Method
        if (num == 1) return true;
        long long i = num / 2;
        while (i * i > num) {
            i = (i + num / i) / 2;
        }
        return i * i == num;
        
        
        // Binary Search
        // int left = 1, right = num;
        // while (left < right) {
        //     int mid = left + (right - left) / 2;
        //     if (mid < num / mid)
        //         left = mid + 1;
        //     else right = mid;
        // }
        // return (num % left == 0) && (left == num / left);
        
        // unordered_set<int> hash;
        // for (long long i = 1; i * i <= INT_MAX; i++)
        //     hash.insert(i * i);
        // return hash.find(num) == hash.end() ? false : true;
    }
};