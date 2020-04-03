#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        size_t len = str.length();

        int idx = 0;
        while (idx < len && str[idx] == ' ') idx++;
        if (idx == len) return 0;

        int sign = 1;
        if (str[idx] == '+') idx++;
        else if (str[idx] == '-') {
            sign = -1;
            idx++;
        }
        int num = 0;
        while (idx < len) {
            char cur = str[idx++];
            if (!isdigit(cur)) break;
            
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (cur - '0') > INT_MAX % 10))
                return INT_MAX;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && (cur - '0') > -(INT_MIN % 10)))
                return INT_MIN;

            num = num * 10 + sign * (cur - '0');
        }
        return num;
    }
};

class Solution2 {
public:
    int myAtoi(string str) {
        auto it = str.begin();
        while (it != str.end() && *it == ' ') it++;
        if (it == str.end() || (*it != '-' && *it != '+' && !isdigit(*it))) return 0;
        int num = 0, flag = 1;
        if (*it == '+') it++;
        else if (*it == '-') {flag = -1; it++;}
        if (it != str.end() && isdigit(*it)) num = flag * (*it++ - '0');
        else return 0;
        while (it != str.end() && isdigit(*it)) {
            if (flag == 1) {
                if (num > (INT_MAX - *it + '0') / 10)
                    return INT_MAX;
                num = num * 10 - '0' + *it;
            } else {
                if (num < (INT_MIN + *it - '0') / 10)
                    return INT_MIN;
                num = num * 10 + '0' - *it ;
            }
            it++;
        }
        return num;
    }
};