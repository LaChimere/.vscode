#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    string stuNo;
    int scores;
};

int main(){
    int n;
    cin >> n;
    Student stu[n];
    for (int i = 0; i < n; i++)
        cin >> stu[i].name >> stu[i].stuNo >> stu[i].scores;
    int maxScoreStu = 0, minScoreStu = 0;
    for (int i = 1; i < n; i++){
        if(stu[i].scores > stu[maxScoreStu].scores)
            maxScoreStu = i;
        if(stu[i].scores < stu[minScoreStu].scores)
            minScoreStu = i;
    }
    cout << stu[maxScoreStu].name << " " << stu[maxScoreStu].stuNo << endl;
    cout << stu[minScoreStu].name << " " << stu[minScoreStu].stuNo;
    return 0;
}