#include <iostream>
using namespace std;

int main(){
    int a, b, d;
    cin >> a >> b >> d;
    int ans = a + b;
    if (ans == 0)
        cout << 0;
    else {
        int s[100];
        int i = 0;
        while (ans != 0){
            s[i++] = ans % d;
            ans /= d;
        }
        for (int j = i - 1; j >= 0; j--)
            cout << s[j];
    }
    return 0;
}