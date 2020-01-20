#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> v;
    string s;
    while (cin >> s)
        v.push_back(s);
    for (int i = v.size() - 1; i >= 0; i--){
        cout << v[i];
        if (i > 0)
            cout << " ";
    }
    return 0;
}