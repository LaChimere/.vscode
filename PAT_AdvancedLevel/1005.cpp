#include <iostream>
using namespace std;

const string NUMBERS[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += s[i] - '0';
    string ans = to_string(sum);
    for (int i = 0; i < ans.length(); i++) {
        cout << NUMBERS[ans[i] - '0'];
        if (i < ans.length() - 1)
            cout << " ";
    }
    return 0;
}