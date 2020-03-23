#include "tools"
class Solution {
private:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
public:
    int dayOfYear(string date) {
        vector<int> d({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int cnt = 0;
        for (int i = 1; i < month; i++) cnt += d[i];
        cnt += day;
        if (month > 2 && isLeap(year)) cnt++;
        return cnt;
    }
};