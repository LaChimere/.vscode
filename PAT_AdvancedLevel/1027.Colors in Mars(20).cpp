#include <cstdio>

void convertRadix(int *s, int x){
    int num = 0;
    do {
        s[num++] = x % 13;
        x /= 13;
    } while (num < 2);
}

void printColor(const int *s){
    for (int i = 1; i >= 0; i--){
        if (s[i] == 10)
            printf("A");
        else if (s[i] == 11)
            printf("B");
        else if (s[i] == 12)
            printf("C");
        else
            printf("%d", s[i]);
    }
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int red[2], green[2], blue[2];
    convertRadix(red, a);
    convertRadix(green, b);
    convertRadix(blue, c);
    printf("#");
    printColor(red);
    printColor(green);
    printColor(blue);
    return 0;
}