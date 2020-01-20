#include <cstdio>

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int k = 1;
    for (; 2 * k * k - 1 <= n; k++);
    k -= 1;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < i - 1; j++)
            printf(" ");
        for (int j = 0; j < 2 * k - 2 * i + 1; j++)
            printf("%c", c);
        printf("\n");
    }
    for (int i = 2; i <= k; i++){
        for (int j = 0; j < k - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            printf("%c", c);
        printf("\n");
    }
    printf("%d", n - 2 * k * k + 1);
    return 0;
}