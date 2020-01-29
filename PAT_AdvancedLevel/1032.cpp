#include <iostream>
using namespace std;

const int MAXSIZE = 100005;
struct node {
    char data;
    int next;
    bool flag;
} words[MAXSIZE];

int main() {
    int head1, head2, n;
    scanf("%d%d%d", &head1, &head2, &n);
    int addr, next;
    char data;
    while (n--) {
        scanf("%d %c %d", &addr, &data, &next);
        words[addr] = {data, next, false};
    }
    for (int i = head1; i != -1; i = words[i].next)
        words[i].flag = true;
    int i;
    for (i = head2; i != -1; i = words[i].next) {
        if (words[i].flag == true)
            break;
    }
    printf("%d", i);
    return 0;
}