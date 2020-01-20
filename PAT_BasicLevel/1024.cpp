#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ePos = 0;
    while (s[ePos] != 'E')
        ePos++;
    string num = s.substr(1, ePos - 1);
    int e = stoi(s.substr(ePos + 1));
    if (s[0] == '-')
        cout << "-";
    if (e < 0) {
        cout << "0.";
        for (int i = 0; i < abs(e) - 1; i++)
            cout << "0";
        for (int i = 0; i < num.length(); i++)
            if (num[i] != '.')
                cout << num[i];
    } else {
        cout << num[0];
        if (e >= num.length() - 2) {
            for (int i = 2; i < num.length(); i++)
                cout << num[i];
            for (int i = 0; i < e - num.length() + 2; i++)
                cout << "0";
        } else {
            int i = 2;
            for (; i < e + 2; i++)
                cout << num[i];
            cout << ".";
            for (; i < num.length(); i++)
                cout << num[i];
        }
    }
    return 0;
}