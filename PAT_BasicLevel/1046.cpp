#include <cstdio>

int main(){
    int N;
    scanf("%d", &N);
    int a, b, c, d;
    int cup1 = 0, cup2 = 0;
    while(N--){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(b == a + c && d != a + c){
            cup2++;
        } else if(b != a + c && d == a + c){
            cup1++;
        }
    }
    printf("%d %d", cup1, cup2);

    return 0;
}