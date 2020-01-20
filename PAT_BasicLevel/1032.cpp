#include <cstdio>

typedef struct _Player{
    int school;
    int score;
    _Player(){
        school = 0;
        score = 0;
    }
} Player;

int getSchoolNumbers(const Player *list, int listLength);

int main(){
    int N;
    scanf("%d", &N);
    Player* playerList = new Player[N];
    for (int i = 0; i < N; i++)
        scanf("%d%d", &playerList[i].school, &playerList[i].score);
    int schoolNumbers = getSchoolNumbers(playerList, N);
    int *schoolNum = new int[schoolNumbers + 1];
    for (int i = 0; i <= schoolNumbers; i++)
        schoolNum[i] = 0;
    for (int i = 0; i < N; i++)
        schoolNum[playerList[i].school] += playerList[i].score;
    int maxScoreSchool = 1;
    for (int i = 2; i <= schoolNumbers; i++){
        if(schoolNum[i] > schoolNum[maxScoreSchool])
            maxScoreSchool = i;
    }
    printf("%d %d", maxScoreSchool, schoolNum[maxScoreSchool]);
    return 0;
}

int getSchoolNumbers(const Player* list, int listLength){
    int maxNum = list[0].school;
    for (int i = 1; i < listLength; i++){
        if(list[i].school > maxNum)
            maxNum = list[i].school;
    }
    return maxNum;
}