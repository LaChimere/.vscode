#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() > b.length())
        b.append(a.length() - b.length(), '0');
    if (a.length() < b.length())
        a.append(b.length() - a.length(), '0');
    int k = 1;
    for (auto itA = a.begin(), itB = b.begin(); itA != a.end() && itB != b.end(); itA++, itB++) {
        if (k % 2) {
            int x = ((*itA - '0') + (*itB - '0')) % 13;
            if (x == 10) *itB = 'J';
            else if (x == 11) *itB = 'Q';
            else if (x == 12) *itB = 'K';
            else *itB = x + '0';
        } else {
            int y = *itB - *itA;
            if (y < 0) y += 10;
            *itB = y + '0';
        }
        k++;
    }
    for (auto it = b.rbegin(); it != b.rend(); it++)
        cout << *it;
    return 0;
}