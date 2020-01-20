#include <iostream>
#include <string>
using namespace std;

bool isPanlindromic(const string s){
    bool flag = true;
    for (int i = 0, j = s.length() - 1; i <= j; i++, j--){
        if (s[i] != s[j])
            flag = false;
    }
    return flag;
}

int main(){
    string s;
    while (cin >> s) {
        if (isPanlindromic(s))
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}