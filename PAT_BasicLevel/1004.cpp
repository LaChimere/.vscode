#include <iostream>
#include <string>
using namespace std;

typedef struct _student{
    string name;
    string number;
    int score;
} Student;

int main(){
    int n;
    cin >> n;
    Student s[n];

    for(int i=0; i<n; i++){
        cin >> s[i].name >> s[i].number >> s[i].score;
    }
    
    int maxone = 0;
    int minone = 0;
    for(int i=1; i<n; i++){
        if(s[i].score > s[maxone].score)
            maxone = i;
        if(s[i].score < s[minone].score)
            minone = i;
    }

    cout << s[maxone].name << " " << s[maxone].number;
    cout << endl;
    cout << s[minone].name << " " << s[minone].number;

    return 0;
}