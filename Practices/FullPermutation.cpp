#include <iostream>
using namespace std;

const int MAXSIZE = 50;
bool HashTable[MAXSIZE] = {false};
int P[MAXSIZE];

void generateP(int index, int n) {
    if (index == n + 1) {
        for (int i = 1; i <= n; i++)
            printf("%d ", P[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (HashTable[i] == false) {
            P[index] = i;
            HashTable[i] = true;
            generateP(index + 1, n);
            HashTable[i] = false;
        }
    }
}

int main() {
    generateP(1, 3);
    return 0;
}