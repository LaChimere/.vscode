#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a + b < 0)
        cout << "-";
    string s = to_string(abs(a + b));
    for (int i = 0; i < s.length(); i++) {
        if (i != 0 && i % 3 == s.length() % 3)
            cout << ",";
        cout << s[i];
    }
    return 0;
}