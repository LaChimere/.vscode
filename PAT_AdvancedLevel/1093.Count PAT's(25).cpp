#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, cnt_p = 0, cnt_t = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
        if (s[i] == 'T')
            cnt_t++;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P')
            cnt_p++;
        if (s[i] == 'T')
            cnt_t--;
        if (s[i] == 'A')
            ans = (ans + (cnt_p * cnt_t) % 1000000007) % 1000000007;
    }
    cout << ans;
    return 0;
}