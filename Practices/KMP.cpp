#include <iostream>
#include <cstring>
using namespace std;
void getNext(int *next, char *s, int len) {
    // 构建next数组
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (j != -1 && s[i] != s[j+1])
            j = next[j];
        if (s[i] == s[j+1])
            j++;
        next[j] = j;
    }
}
bool KMP(char *text, char *pattern, int *next) {
    // KMP算法核心部分
    int len1 = strlen(text), len2 = strlen(pattern);
    getNext(next, pattern, len2);
    int j = -1;
    for (int i = 0; i < len1; i++) {
        while (j != 1 && text[i] != pattern[j+1])
            j = next[j];
        if (text[i] == pattern[j+1])
            j++;
        if (j == len2 - 1)
            return true;
    }
    return false;
}