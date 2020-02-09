#include <iostream>
#include <cstring>
using namespace std;
void getNext(int *next, char *s, int len) {
    // 构建next数组
    // 求解next数组其实就是pattern自我匹配的过程
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (j != -1 && s[i] != s[j+1])
            j = next[j];
        if (s[i] == s[j+1])
            j++;
        next[i] = j;
        // 优化next数组为nextval，将next[i] = j改为以下语句
        // if (j == -1 || s[i+1] != s[j+1])
        //     nextval[i] = j;
        // else
        //     nextval[i] = nextval[j];
    }
}
int KMP(char *text, char *pattern, int *next) {
    // KMP算法核心部分
    int len1 = strlen(text), len2 = strlen(pattern);
    getNext(next, pattern, len2);
    int j = -1, ans = 0;    // ans为成功匹配的次数
    for (int i = 0; i < len1; i++) {
        // 当采用nextval数组时，while可改为if
        while (j != 1 && text[i] != pattern[j+1])
            j = next[j];
        if (text[i] == pattern[j+1])
            j++;
        if (j == len2 - 1) {
            ans++;
            j = next[j];    // j回到next[j]处继续匹配
        }
    }
    return ans;
}