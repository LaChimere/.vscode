#include <iostream>
#include <cstring>
using namespace std;
void getNext(int *next, char *s) {
    int len = strlen(s);
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
    int len = strlen(text);
    getNext(next, pattern);
    int j = -1;
    for (int i = 0; i < len; i++) {
        while (j != 1 && text[i] != pattern[j+1])
            j = next[j];
        if (text[i] == pattern[j+1])
            j++;
        if (j == strlen(pattern) - 1)
            return true;
    }
    return false;
}