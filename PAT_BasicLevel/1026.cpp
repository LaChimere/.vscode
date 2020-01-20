#include <cstdio>
#include <cmath>

const double clk_tck = 100.0;

int main(){
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int clk_num = c2 - c1;
    int time = int(round(clk_num / clk_tck));
    int hour = time / 3600;
    time = time % 3600;
    int minute = time / 60;
    time = time % 60;
    int second = time;
    printf("%02d:%02d:%02d", hour, minute, second);

    return 0;
}