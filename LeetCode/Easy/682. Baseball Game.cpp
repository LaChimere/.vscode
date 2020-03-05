#include "tools"
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> roundPoints;
        for (string s : ops) {
            if (s == "+") {
                int last1 = roundPoints.top();
                roundPoints.pop();
                int last2 = roundPoints.top();
                int nowRound = last1 + last2;
                roundPoints.push(last1);
                roundPoints.push(nowRound);
            } else if (s == "D") {
                roundPoints.push(roundPoints.top() * 2);
            } else if (s == "C") {
                roundPoints.pop();
            } else {
                roundPoints.push(stoi(s));
            }
        }
        int points = 0;
        while (!roundPoints.empty()) {
            points += roundPoints.top();
            roundPoints.pop();
        }
        return points;
    }
};