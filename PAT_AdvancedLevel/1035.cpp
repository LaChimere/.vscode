#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isModified(string &s) {
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            s[i] = '@';
            flag = true;
        } else if (s[i] == '0') {
            s[i] = '%';
            flag = true;
        } else if (s[i] == 'l') {
            s[i] = 'L';
            flag = true;
        } else if (s[i] == 'O') {
            s[i] = 'o';
            flag = true;
        }
    }
    return flag;
}

int main() {
    int n;
    cin >> n;
    vector<string> account(n), password(n);
    vector<bool> modified(n, false);
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> account[i] >> password[i];
        if (isModified(password[i])) {
            cnt++;
            flag = false;
            modified[i] = true;
        }
    }
    if (!flag) {
        cout << cnt << endl;
        for (int i = 0; i < n; i++) {
            if (modified[i])
                cout << account[i] << " " << password[i] << endl;
        }
    }
    if (flag && n == 1)
        cout << "There is 1 account and no account is modified";
    else if (flag && n > 1)
        cout << "There are " << n << " accounts and no account is modified";
    return 0;
}