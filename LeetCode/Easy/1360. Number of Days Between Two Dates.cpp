#include "tools"
class Solution {
private:
    vector<int> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    int getDate(string date) {
        int year, month, day, ans = 0;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        for (int y = 1971; y < year; y++) {
            if (isLeap(y)) ans += 366;
            else ans += 365;
        }
        for (int m = 1; m < month; m++) ans += months[m];
        ans += day;
        if (month > 2 && isLeap(year)) ans += 1;
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(getDate(date2) - getDate(date1));
    }
};