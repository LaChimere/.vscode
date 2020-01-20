#include <cstdio>

int main(){
    double n1[1001] = {0.0}, n2[1001] = {0.0};
    int k1, k2;
    scanf("%d", &k1);
    int e1, e2;
    double a1, a2;
    while(k1--){
        scanf("%d%lf", &e1, &a1);
        n1[e1] = a1;
    }
    scanf("%d", &k2);
    while(k2--){
        scanf("%d%lf", &e2, &a2);
        n2[e2] = a2;
    }
    double answer[1001];
    for (int i = 0; i < 1001; i++)
        answer[i] = n1[i] + n2[i];
    int non_answer = 0;
    for (int i = 0; i < 1001; i++){
        if(answer[i])
            non_answer++;
    }
    printf("%d", non_answer);
    for (int i = 1000; i >= 0; i--){
        if(answer[i])
            printf(" %d %.1f", i, answer[i]);
    }
    return 0;
}