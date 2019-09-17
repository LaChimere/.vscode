#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int flag = 0;
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    M %= N;             //this line is extremely critical!
    if(M > 0){
        reverse(begin(a), begin(a) + N);
        reverse(begin(a), begin(a) + M);
        reverse(begin(a) + M, begin(a) + N);
    }
    for (int i = 0; i < N; i++){
        if(flag == 1)
            cout << " ";
        cout << a[i];
        flag = 1;
    }
        return 0;
}