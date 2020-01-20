#include <cstdio>

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 0; i < n; i++)
        printf("%c", c);
    printf("\n");
    int rows;
    if (n % 2)
        rows = n / 2 + 1;
    else
        rows = n / 2;
    for (int i = 0; i < rows - 2; i++){
        printf("%c", c);
        for (int j = 0; j < n - 2; j++)
            printf(" ");
        printf("%c\n", c);
    }
    for (int i = 0; i < n; i++)
        printf("%c", c);
    return 0;
}