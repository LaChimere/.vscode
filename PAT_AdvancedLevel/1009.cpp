#include <cstdio>

int main(){
    double n[1001] = {0.0};
    int k, e;
    double a;
    scanf("%d", &k);
    while(k--){
        scanf("%d%lf", &e, &a);
        n[e] = a;
    }
    double answer[2001] = {0.0};
    scanf("%d", &k);
    while(k--){
        scanf("%d%lf", &e, &a);
        for (int i = 0; i < 1001; i++)
            answer[i + e] += n[i] * a;
    }
    int non_zero = 0;
    for (int i = 0; i < 2001; i++){
        if(answer[i])
            non_zero++;
    }
    printf("%d", non_zero);
    for (int i = 2000; i >= 0; i--){
        if(answer[i])
            printf(" %d %.1f", i, answer[i]);
    }
    return 0;
}