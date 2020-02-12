#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    char c = '3';
    printf("c = %c\n", c);
    c = tolower(c);
    printf("c = %c", c);
    return 0;
}