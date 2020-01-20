#include <iostream>
using namespace std;

int shortestDistance(int x, int y, int cCycle, const int *dist){
    int d1 = 0, d2 = 0, dMin = 0;
    if(x > y){
        int temp = x;
        x = y;
        y = temp;
    }
    for (int i = x; i < y; i++)
        d1 += dist[i];
    d2 = cCycle - d1;
    dMin = d1 < d2 ? d1 : d2;
    return dMin;
}

int main(){
    int n, m;
    cin >> n;
    int *d = new int[n + 1];
    int totalDist = 0;
    for (int i = 1; i < n + 1; i++){
        cin >> d[i];
        totalDist += d[i];
    }
    cin >> m;
    int e1, e2;
    while(m--){
        cin >> e1 >> e2;
        cout << shortestDistance(e1, e2, totalDist, d) << endl;
    }
    delete[] d;
    return 0;
}