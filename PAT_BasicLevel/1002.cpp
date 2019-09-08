#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int sum = 0;
    string str[10] = {"ling","yi","er","san","si",
                        "wu","liu","qi","ba","jiu"};
    for(int i=0; i<s.length(); i++){
        sum += (s[i] - '0');
    }
    string num = to_string(sum);
    for(int i=0; i<num.length(); i++){
        cout<<str[num[i]-'0'];
        if(i<num.length()-1)
            cout<<" ";
    }
    return 0;
}