#include <cstdio>

const int month[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
                         {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool isLeapYear(int year){
    bool flag = false;
    if (year % 4 == 0 && year % 400 != 0)
        flag = true;
    return flag;
}

void Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int date1, date2;
    int y1, y2, m1, m2, d1, d2;
    while (scanf("%d%d", &date1, &date2) != EOF){
        if (date1 > date2)
            Swap(date1, date2);
        y1 = date1 / 10000;
        y2 = date2 / 10000;
        m1 = (date1 % 10000) / 100;
        m2 = (date2 % 10000) / 100;
        d1 = date1 % 100;
        d2 = date2 % 100;
        int ans = 1;
        while (y1 < y2 || m1 < m2 || d1 < d2){
            d1++;
            if (d1 == month[m1][isLeapYear(y1)] + 1){
                m1++;
                d1 = 1;
            }
            if (m1 == 13){
                y1++;
                m1 = 1;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}