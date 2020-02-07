#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const char a, const char b) {return a > b;}

int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.length(), '0');
    do {
        string up = s, low = s;
        sort(up.begin(), up.end(), cmp);
        sort(low.begin(), low.end());
        int result = stoi(up) - stoi(low);
        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');
        cout << up << " - " << low << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}