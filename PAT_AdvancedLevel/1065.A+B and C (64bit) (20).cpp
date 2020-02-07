#include <iostream>
using namespace std;

int main(){
    int t;
    long long int a, b, c;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if(a > 0 && b > 0 && a + b < 0)
            cout << "Case #" << i << ": true\n";
        else if(a < 0 && b < 0 && a + b >=0)
            cout << "Case #" << i << ": false\n";
        else if(a + b > c)
            cout << "Case #" << i << ": true\n";
        else
            cout << "Case #" << i << ": false\n";
    }
    return 0;
}