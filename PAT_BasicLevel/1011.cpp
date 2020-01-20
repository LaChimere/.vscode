#include <cstdio>

bool isMore(long int x, long int y){
    bool flag = false;
    if(x > y)
        flag = true;
    return flag;
}

int main(){
    int T;
    scanf("%d", &T);
    long int a, b, c;
    for (int i = 1; i <= T; i++){
        scanf("%ld%ld%ld", &a, &b, &c);
        if(isMore(a + b, c))
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}