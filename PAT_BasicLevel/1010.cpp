#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> fx;
    int x;
    while(cin >> x)
        fx.push_back(x);
    for (int i = 0; i < fx.size(); i += 2){
        fx[i] *= fx[i + 1];
        fx[i + 1] -= 1;
    }
    if(fx[0] == 0)
        cout << "0 0";
    else{
        for (int i = 0; i < fx.size(); i += 2){
            if(fx[i] != 0){
                if(i > 0)
                    cout << " ";
                cout << fx[i] << " " << fx[i + 1];
            }
        }
    }
    return 0;
}