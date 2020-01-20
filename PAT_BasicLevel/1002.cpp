#include <iostream>
#include <string>
using namespace std;

const string PINYIN[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += s[i] - '0';
    string result = to_string(sum);
    for (int i = 0; i < result.length(); i++) {
        cout << PINYIN[result[i] - '0'];
        if (i < result.length() - 1)
            cout << " ";
    }
    return 0;
}