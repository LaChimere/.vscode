#include <cstdio>

int main(){
    long long int a, b;
    int da, db;
    scanf("%lld%d%lld%d", &a, &da, &b, &db);
    int pa = 0, pb = 0;
    while(a){
        if(a % 10 == da)
            pa = pa * 10 + da;
        a = a / 10;
    }
    while(b){
        if(b % 10 == db)
            pb = pb * 10 + db;
        b = b / 10;
    }
    printf("%d", pa + pb);
    
    return 0;
}