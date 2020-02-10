#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s = "123";
    cout << s << endl;
    s.append(2, '4');
    cout << s << endl;
    s.append(0, '5');
    cout << s << endl;
    return 0;
}