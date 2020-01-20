#include <cstdio>

int main(){
    int num[10] = {0};
    char x[1001];
    scanf("%s", &x);
    for (int i = 0; x[i] != '\0'; i++)
        num[x[i] - '0']++;
    for (int i = 0; i < 10; i++)
        if (num[i] != 0)
            printf("%d:%d\n", i, num[i]);
    return 0;
}