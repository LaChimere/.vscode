#include <cstdio>

const int GALLEON = 17;
const int SICKLE = 29;

int main(){
    int a1, b1, c1;
    int a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int ansG = a1 + a2, ansS = b1 + b2, ansK = c1 + c2;
    if (ansK >= SICKLE){
        ansS += 1;
        ansK -= SICKLE;
    }
    if (ansS >= GALLEON){
        ansG += 1;
        ansS -= GALLEON;
    }
    printf("%d.%d.%d", ansG, ansS, ansK);
    return 0;
}