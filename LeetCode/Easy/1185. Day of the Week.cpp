#include "tools"
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if (month == 1 || month == 2) month += 12, year--;
        // Kim larsen calculation formula
        int iWeek = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
        vector<string> res({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
        return res[iWeek];
    }
};