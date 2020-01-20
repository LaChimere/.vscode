#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, num, a1 = 0, a2 = 0, a5 = 0;
    double a4 = 0.0;
    cin >> n;
    vector<int> v[5];
    for (int i = 0; i < n; i++){
        cin >> num;
        v[num % 5].push_back(num);
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < v[i].size(); j++){
            if(i == 0 && v[i][j] % 2 == 0) a1 += v[i][j];
            if(i == 1 && j % 2 == 0) a2 += v[i][j];
            if(i == 1 && j % 2 == 1) a2 -= v[i][j];
            if(i == 3) a4 += v[i][j];
            if(i == 4 && v[i][j] > a5) a5 = v[i][j];
        }
    }
    for (int i = 0; i < 5; i++){
        if(i != 0) printf(" ");
        if((i == 0 && a1 == 0) || (i != 0 && v[i].size() == 0)){
            printf("N"); continue;
        }
        if(i == 0) printf("%d", a1);
        if(i == 1) printf("%d", a2);
        if(i == 2) printf("%d", v[2].size());
        if(i == 3) printf("%.1f", a4 / v[3].size());
        if(i == 4) printf("%d", a5);
    }
    return 0;
}

// #include <cstdio>
// #include <vector>
// using namespace std;

// int main(){
//     int n, num, a1 = 0, a2 = 0, a5 = 0;
//     double a4 = 0.0;
//     scanf("%d", &n);
//     vector<int> v[5];
//     for (int i = 0; i < n; i++){
//         scanf("%d", &num);
//         v[num % 5].push_back(num);
//     }
//     for (int i = 0; i < 5; i++){
//         for (int j = 0; j < v[i].size(); j++){
//             if(i == 0 && v[i][j] % 2 == 0) a1 += v[i][j];
//             if(i == 1 && j % 2 == 0) a2 += v[i][j];
//             if(i == 1 && j % 2 == 1) a2 -= v[i][j];
//             if(i == 3) a4 += v[i][j];
//             if(i == 4 && v[i][j] > a5) a5 = v[i][j];
//         }
//     }
//     for (int i = 0; i < 5; i++){
//         if(i != 0) printf(" ");
//         if(v[i].size() == 0){
//             printf("N"); continue;
//         }
//         if(i == 0) printf("%d", a1);
//         if(i == 1) printf("%d", a2);
//         if(i == 2) printf("%d", v[2].size());
//         if(i == 3) printf("%.1f", a4 / v[3].size());
//         if(i == 4) printf("%d", a5);
//     }
//     return 0;
// }
