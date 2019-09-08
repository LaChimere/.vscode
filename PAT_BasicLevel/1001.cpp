#include <iostream>
using namespace std;
int main(){
    int n;
    int k = 0;
    cin>>n;
    if(n>=0 && n<=1000){
        while(n!=1){
            if(n%2==0){
                n /= 2;
            }
            else{
                n = (3*n + 1) / 2;
            }
            k++;
        }
    }
    cout<<k;
    return 0;
}