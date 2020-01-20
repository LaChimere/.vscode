#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();  // 接收换行符
    vector<string> str(n);
    int minLen = 256;
    for (int i = 0; i < n; i++) {
        getline(cin, str[i]);
        reverse(str[i].begin(), str[i].end());
        if (str[i].length() < minLen)
            minLen = str[i].length();
    }
    int sameLen = 1;
    bool flag = true;
    while (sameLen <= minLen) {
        for (int i = 1; i < n; i++)
            if (str[0].substr(0, sameLen) != str[i].substr(0, sameLen)) {
                flag = false;
                break;
            }
        if (!flag)
            break;
        sameLen++;
    }
    sameLen -= 1;
    if (sameLen == 0)
        cout << "nai";
    else
        for (int i = sameLen - 1; i >= 0; i--)
            cout << str[0][i];
    return 0;
}