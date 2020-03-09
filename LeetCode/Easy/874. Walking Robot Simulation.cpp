#include "tools"
class Solution {
private:
    set<vector<int>> ob;
    int move(int command, int& state, int& x, int& y) {
        if (command == -2) state = (state + 3) % 4;
        else if (command == -1) state = (state + 1) % 4;
        else {
            switch(state) {
                case 0: while (command-- && !isOb(x, y + 1)) y++;
                    break;
                case 1: while (command-- && !isOb(x + 1, y)) x++;
                    break;
                case 2: while (command-- && !isOb(x, y - 1)) y--;
                    break;
                case 3: while (command-- && !isOb(x - 1, y)) x--;
                    break;
            }
        }
        return x * x + y * y;
    }
    bool isOb(int x, int y) {return ob.count({x, y});}
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxD = 0, x = 0, y = 0;
        for (vector<int> obstacle : obstacles) ob.insert(obstacle);
        int state = 0;
        for (int command : commands)
            maxD = max(maxD, move(command, state, x, y));
        return maxD;
    }
};