#include "tools"
class Solution {
public:
    bool isHappy(int n) {
        // using fast and slow pointers
        int slow = n, fast = n;
        do {
            slow = getSquareSum(slow);
            fast = getSquareSum(fast);
            fast = getSquareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }

    int getSquareSum(int n) {
        int sum = 0;
        while (n != 0) {
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }
        return sum;
    }
};


// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_map<int, bool> hash;
//         return isHappy(n, hash, 0);
//     }
    
//     bool isHappy(int n, unordered_map<int, bool>& hash, int k) {
//         if (n == 1) {hash[n] = true; return hash[n];}
//         if (hash.find(n) != hash.end()) return hash[n];
//         if (k > 99) {hash[n] = false; return hash[n];}
//         if (isHappy(getSquare(n), hash, k + 1)) hash[n] = true;
//         else hash[n] = false;
//         return hash[n];
//     }
    
//     int getSquareSum(int n) {
//         int sum = 0;
//         while (n != 0) {
//             int remainder = n % 10;
//             sum += remainder * remainder;
//             n /= 10;
//         }
//         return sum;
//     }
// };