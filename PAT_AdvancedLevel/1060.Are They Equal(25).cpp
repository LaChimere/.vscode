#include <iostream>
#include <string>
using namespace std;

string stringDeal(string s, int &e, const int precise) {
    int k = 0;
    while (s.length() > 0 && s[0] == '0')
        s.erase(s.begin());
    if (s[0] == '.') {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
    } else {
        while (k < s.length() && s[k] != '.') {
            k++;
            e++;
        }
        if (k < s.length())
            s.erase(s.begin() + k);
    }
    if (s.length() == 0)
        e = 0;
    string ret;
    for (k = 0; k < precise; k++) {
        if (k < s.length())
            ret += s[k];
        else
            ret += '0';
    }
    return ret;
}

int main() {
    int n, a_e = 0, b_e = 0;;
    string a, b, a_dealed, b_dealed;
    cin >> n >> a >> b;
    a_dealed = stringDeal(a, a_e, n);
    b_dealed = stringDeal(b, b_e, n);
    if (a_dealed == b_dealed && a_e == b_e)
        cout << "YES 0." << a_dealed << "*10^" << a_e;
    else
        cout << "NO 0." << a_dealed << "*10^" << a_e << " 0." << b_dealed << "*10^" << b_e;
    return 0;
}