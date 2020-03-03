#include "tools"
class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0, vertical = 0;
        for (char c : moves) {
            switch (c) {
                case 'R' : horizontal++;
                    break;
                case 'L' : horizontal--;
                    break;
                case 'U' : vertical++;
                    break;
                case 'D' : vertical--;
                    break;
            }
        }
        return horizontal == 0 && vertical == 0;
    }
};