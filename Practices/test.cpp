#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <bitset>
#include <string>
using namespace std;

int main() {
    uint32_t n = 20;
    cout << bitset<32>(n);
    bitset<32> mybit(n);
    string s = mybit.to_string();
    cout << endl << s;
    reverse(s.begin(), s.end());
    cout << endl << s;
    long m = stol(s, NULL, 2);
    cout << endl << m;
    bitset<32> mybit2(m);
    cout << endl << mybit2;
    return 0;
}