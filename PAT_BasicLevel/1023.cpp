#include <iostream>
using namespace std;

int main() {
    int num[10];
    int k = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
        k += num[i];
    }
    for (int i = 1; i < 10; i++) {
        if (num[i] != 0) {
            printf("%d", i);
            num[i]--;
            k--;
            break;
        }
    }
    while (k--) {
        for (int i = 0; i < 10; i++) {
            if (num[i] != 0) {
                printf("%d", i);
                num[i]--;
                break;
            }
        }
    }
    return 0;
}