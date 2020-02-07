#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const string NUMBERS[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const string S[3] = {"Shi", "Bai", "Qian"};

int main() {
    int x;
    cin >> x;
    if (x == 0) {
        // 需要特判0
        cout << "ling";
        return 0;
    }
    if (x < 0) {
        cout << "Fu ";
        x = -x;
    }
    string str = to_string(x);
    if (str.length() < 9) {
        reverse(str.begin(), str.end());
        str.append(9 - str.length(), '0');
        reverse(str.begin(), str.end());
    }
    bool printBlank = false;
    if (str[0] != '0') {
        cout << NUMBERS[str[0] - '0'] << " Yi";
        printBlank = true;
    }
    if (str.substr(1, 4) != "0000") {
        for (int i = 1; i < 4; i++) {
            if (str[i] != '0') {
                if (printBlank)
                    cout << " ";
                cout << NUMBERS[str[i] - '0'] << " " << S[3 - i];
                printBlank = true;
            } else if (str[i - 1] != '0' && str[i] == '0') {
                bool printZero = false;
                for (int j = i + 1; j <= 4; j++) {
                    if (str[j] != '0') {
                        printZero = true;
                        break;
                    }
                }
                if (printZero)
                    cout << " ling";
            }
        }
        if (str[4] != '0') {
            if (printBlank)
                cout << " ";
            cout << NUMBERS[str[4] - '0'];
            printBlank = true;
        }
        cout << " Wan";
    }
    if (str.substr(5, 4) != "0000") {
        if (str[4] == '0' && str[5] == '0')
            cout << " ling";
        for (int i = 5; i < 8; i++) {
            if (str[i] != '0') {
                if (printBlank)
                    cout << " ";
                cout << NUMBERS[str[i] - '0'] << " " << S[7 - i];
                printBlank = true;
            } else if (str[i - 1] != '0' && str[i] == '0') {
                bool printZero = false;
                for (int j = i + 1; j <= 8; j++) {
                    if (str[j] != '0') {
                        printZero = true;
                        break;
                    }
                }
                if (printZero)
                    cout << " ling";
            }
        }
        if (str[8] != '0') {
            if (printBlank)
                cout << " ";
            cout << NUMBERS[str[8] - '0'];
            printBlank = true;
        }
    }
    return 0;
}