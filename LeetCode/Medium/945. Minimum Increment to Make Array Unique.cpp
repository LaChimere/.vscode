#include "tools"
class Solution {
private:
    vector<int> pos = vector<int>(80000, -1);
    int findPos(int a) {
        if (pos[a] == -1) pos[a] = a;
        else pos[a] = findPos(pos[a] + 1);
        return pos[a];
    }
public:
    int minIncrementForUnique(vector<int>& A) {
        int moves = 0;
        for (int a : A) moves += findPos(a) - a;
        return moves;
    }
};