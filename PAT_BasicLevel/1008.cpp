#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> numList(N);
    for (int i = 0; i < N; i++)
        cin >> numList[i];
    // M %= N is of great significance (what if M > N?)
    M %= N;
    if(M > 0){
        reverse(numList.begin(), numList.begin() + N);
        reverse(numList.begin(), numList.begin() + M);
        reverse(numList.begin() + M, numList.begin() + N);
    }
    for (int i = 0; i < N; i++){
        cout << numList[i];
        if(i < N - 1)
            cout << " ";
    }
    return 0;
}