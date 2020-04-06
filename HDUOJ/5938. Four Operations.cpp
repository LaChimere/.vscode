#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        string s;
        cin >> s;

        long long result = INT_MIN, len = s.length();
        for (int i = 1; i <= 2; i++) {
            int e = stoi(s.substr(len - i, i));
            int d = s[len - i - 1] - '0';
            int c = s[len - i - 2] - '0';
            long long a, b;
            for (int j = 1; j < len - i - 2; j++) {
                a = stoll(s.substr(0, j));
                b = stoll(s.substr(j, len - i - 2 - j));
                result = max(result, a + b - c * d / e);
            }
        }

        printf("Case #%d: %lld\n", k, result);
    }

    return 0;
}