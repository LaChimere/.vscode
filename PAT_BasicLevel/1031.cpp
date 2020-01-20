#include <iostream>
#include <string>
using namespace std;

const int WEIGHT[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char Z_TO_M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isNormal(const string s) {
    bool flag = true;
    int sum = 0;
    for (int i = 0; i < 17; i++) {
        if (s[i] < '0' || s[i] > '9') {
            flag = false;
            break;
        }
        sum += (s[i] - '0') * WEIGHT[i];
    }
    if (flag)
        if (Z_TO_M[sum % 11] != s[17])
            flag = false;
    return flag;
}

int main() {
    int n;
    cin >> n;
    string s;
    bool flag = true;
    while (n--) {
        cin >> s;
        if (!isNormal(s)) {
            flag = false;
            cout << s << endl;
        }
    }
    if (flag)
        cout << "All passed";
    return 0;
}