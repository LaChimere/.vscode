#include "tools"
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.length() - 1;
        while (left < right) {
            while (left < S.length() && !isalpha(S[left])) left++;
            while (right >= 0 && !isalpha(S[right])) right--;
            if (left < right) swap(S[left++], S[right--]);
        }
        return S;
    }
};