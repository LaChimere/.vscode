#include "tools"
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        if (target >= letters[right] || target < letters[left]) return letters[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (target < letters[mid]) right = mid;
            else left = mid;
        }
        return letters[right];
    }
};