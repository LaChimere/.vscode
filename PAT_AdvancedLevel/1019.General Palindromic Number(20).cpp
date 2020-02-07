#include <iostream>
#include <vector>
using namespace std;

bool isPalindromic(const vector<int> v){
    bool flag = true;
    for (int i = 0, j = v.size() - 1; i <= j; i++, j--){
        if (v[i] != v[j])
            flag = false;
    }
    return flag;
}

int main(){
    int n, b;
    cin >> n >> b;
    vector<int> v;
    do {
        v.push_back(n % b);
        n /= b;
    } while (n != 0);
    if (isPalindromic(v))
        cout << "Yes\n";
    else
        cout << "No\n";
    for (int i = v.size() - 1; i >= 0; i--){
        cout << v[i];
        if (i > 0)
            cout << " ";
    }
    return 0;
}