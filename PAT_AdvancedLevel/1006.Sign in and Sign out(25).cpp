#include <iostream>
#include <string>
using namespace std;

int main(){
    int m;
    cin >> m;
    string ID_number, Sign_in_time, Sign_out_time;
    string unlock_ID, lock_ID, unlock_time = "23:59:59", lock_time = "00:00:00";
    while(m--){
        cin >> ID_number >> Sign_in_time >> Sign_out_time;
        if(Sign_in_time < unlock_time){
            unlock_time = Sign_in_time;
            unlock_ID = ID_number;
        }
        if(Sign_out_time > lock_time){
            lock_time = Sign_out_time;
            lock_ID = ID_number;
        }
    }
    cout << unlock_ID << " " << lock_ID;
    return 0;
}