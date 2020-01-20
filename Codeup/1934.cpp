#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n, x;
    while(scanf("%d", &n) != EOF){
        vector<int> v;
        int a;
        while(n--){
            scanf("%d", &a);
            v.push_back(a);
        }
        scanf("%d", &x);
        int i = 0;
        for (; i < v.size(); i++){
            if(v[i] == x){
                printf("%d\n", i);
                break;
            }
        }
        if(i == v.size())
            printf("-1\n");
    }
    return 0;
}