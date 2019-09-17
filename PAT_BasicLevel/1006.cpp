#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int b = n / 100;
    n = n % 100;
    int s = n / 10;
    n = n % 10;
    int g = n;
    while(b--)
        cout << "B";
    while(s--)
        cout << "S";
    for(int i = 1; i <= g; i++)
        cout << i;
    return 0;
}