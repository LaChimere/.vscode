#include <cstdio>

int main(){
    char signal[4] = "WTL";
    double product = 1.0;
    for (int i = 0; i < 3; i++){
        double tempMax = 0.0;
        int maxJ = 0;
        for (int j = 0; j < 3; j++){
            double temp;
            scanf("%lf", &temp);
            if(temp > tempMax){
                tempMax = temp;
                maxJ = j;
            }
        }
        product *= tempMax;
        printf("%c ", signal[maxJ]);
    }
    double profit = (product * 0.65 - 1) * 2;
    printf("%.2f", profit);
    return 0;
}