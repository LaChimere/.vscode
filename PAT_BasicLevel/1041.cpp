#include <cstdio>

struct Student{
    long long int examNo;
    int testSeat;
    int examSeat;
};

int main(){
    int n;
    scanf("%d", &n);
    Student stu[n];
    for (int i = 0; i < n; i++)
        scanf("%lld%d%d", &stu[i].examNo, &stu[i].testSeat, &stu[i].examSeat);
    int m;
    scanf("%d", &m);
    int searchNo;
    while(m--){
        scanf("%d", &searchNo);
        for (int i = 0; i < n; i++){
            if(searchNo == stu[i].testSeat)
                printf("%lld %d\n", stu[i].examNo, stu[i].examSeat);
        }
    }
    return 0;
}