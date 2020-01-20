#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string maxDate = "1814/09/06";
    string minDate = "2014/09/06";
    string name, dateOfBirth, oldestCitizen, youngestCitizen;
    int legalCitizens = 0;
    for (int i = 0; i < n; i++){
        cin >> name >> dateOfBirth;
        if(dateOfBirth >= "1814/09/06" && dateOfBirth <= "2014/09/06"){
            legalCitizens++;
            if(dateOfBirth >= maxDate){
                maxDate = dateOfBirth;
                youngestCitizen = name;
            }
            if(dateOfBirth <= minDate){
                minDate = dateOfBirth;
                oldestCitizen = name;
            }
        }
    }
    cout << legalCitizens;
    if (legalCitizens)
        cout << " " << oldestCitizen << " " << youngestCitizen;
    return 0;
}