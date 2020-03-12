#include "tools"
class Solution {
private:
    int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.length(), str2.length()));
        
        // int len1 = str1.length(), len2 = str2.length();
        // int len = gcd(len1, len2);
        // string s1 = str1.substr(0, len), s2 = str2.substr(0, len);
        // if (s1 != s2) return "";
        // for (int i = len; i < len1; i += len)
        //     if (s1 != str1.substr(i, len)) return "";
        // for (int i = len; i < len2; i += len)
        //     if (s2 != str2.substr(i, len)) return "";
        // return s1;
    }
};