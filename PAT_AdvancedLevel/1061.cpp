#include <iostream>
#include <string>
using namespace std;

const string WEEK[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    char firstUpper, secondChar;
    int samePosition;
    auto it1 = s1.begin(), it2 = s2.begin();
    for (; it1 != s1.end() && it2 != s2.end(); it1++, it2++) {
        // 如果是*it1 >= 'A' && *it1 <= 'Z'则会出现“答案错误”
        if (*it1 == *it2 && *it1 >= 'A' && *it1 <= 'G') {
            firstUpper = *it1;
            break;
        }
    }
    // 迭代器向后移动一个单位，否则还是上面那个循环的字符
    it1++, it2++;
    for (; it1 != s1.end() && it2 != s2.end(); it1++, it2++) {
        if (*it1 == *it2 && ((*it1 >= '0' && *it1 <= '9') || (*it1 >= 'A' && *it1 <= 'N'))) {
            secondChar = *it1;
            break;
        }
    }
    for (int i = 0, j = 0; i < s3.length() && j < s4.length(); i++, j++) {
        if (s3[i] == s4[j] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
            samePosition = i;
            break;
        }
    }
    cout << WEEK[firstUpper - 'A'] << " ";
    if (secondChar >= '0' && secondChar <= '9')
        cout << "0" << secondChar << ":";
    else
        cout << secondChar - 'A' + 10 << ":";
    printf("%02d", samePosition);
    return 0;
}