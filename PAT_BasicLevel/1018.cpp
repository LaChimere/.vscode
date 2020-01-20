#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int tableA[3] = {0}, tableB[3] = {0};
    int postureA[3] = {0}, postureB[3] = {0};
    char a, b;
    while(N--){
        cin >> a >> b;
        if(a == 'B'){
            if(b == 'B'){
                tableA[1]++;
                tableB[1]++;
            } else if(b == 'C'){
                tableA[0]++;
                tableB[2]++;
                postureA[0]++;
            } else if(b == 'J'){
                tableA[2]++;
                tableB[0]++;
                postureB[2]++;
            }
        } else if(a == 'C'){
            if(b == 'B'){
                tableA[2]++;
                tableB[0]++;
                postureB[0]++;
            } else if(b == 'C'){
                tableA[1]++;
                tableB[1]++;
            } else if(b == 'J'){
                tableA[0]++;
                tableB[2]++;
                postureA[1]++;
            }
        } else if(a == 'J'){
            if(b == 'B'){
                tableA[0]++;
                tableB[2]++;
                postureA[2]++;
            } else if(b == 'C'){
                tableA[2]++;
                tableB[0]++;
                postureB[1]++;
            } else if(b == 'J'){
                tableA[1]++;
                tableB[1]++;
            }
        }
    }
    cout << tableA[0] << " " << tableA[1] << " " << tableA[2] << endl;
    cout << tableB[0] << " " << tableB[1] << " " << tableB[2] << endl;
    char resultA = 'B', resultB = 'B';
    int maxA = postureA[0], maxB = postureB[0];
    if(postureA[1] > maxA){
        maxA = postureA[1];
        resultA = 'C';
    }
    if(postureB[1] > maxB){
        maxB = postureB[1];
        resultB = 'C';
    }
    if(postureA[2] > maxA){
        maxA = postureA[2];
        resultA = 'J';
    }
    if(postureB[2] > maxB){
        maxB = postureB[2];
        resultB = 'J';
    }
    cout << resultA << " " << resultB;

    return 0;
}