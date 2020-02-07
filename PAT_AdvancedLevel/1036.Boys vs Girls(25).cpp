#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string female, male;
    int femaleGrade = -1, maleGrade = 101;
    while(n--){
        string name, gender, id;
        int grade;
        cin >> name >> gender >> id >> grade;
        if(gender == "F"){
            if(grade > femaleGrade){
                femaleGrade = grade;
                female = name + " " + id;
            }
        }
        if(gender == "M"){
            if(grade < maleGrade){
                maleGrade = grade;
                male = name + " " + id;
            }
        }
    }
    if(femaleGrade != -1)
        cout << female << endl;
    else
        cout << "Absent\n";
    if(maleGrade != 101)
        cout << male << endl;
    else
        cout << "Absent\n";
    if(femaleGrade != -1 && maleGrade != 101)
        cout << femaleGrade - maleGrade;
    else
        cout << "NA";
    return 0;
}