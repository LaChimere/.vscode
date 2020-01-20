#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int pG, pS, pK, aG, aS, aK;
    scanf("%d.%d.%d %d.%d.%d", &pG, &pS, &pK, &aG, &aS, &aK);
    int p = pG * 17 * 29 + pS * 29 + pK;
    int a = aG * 17 * 29 + aS * 29 + aK;
    int changes = fabs(a - p);
        int cG = changes / (29 * 17);
        int cS = (changes % (29 * 17)) / 29;
        int cK = changes % 29;
    if (a < p)
        printf("-");
    printf("%d.%d.%d", cG, cS, cK);
    return 0;
}