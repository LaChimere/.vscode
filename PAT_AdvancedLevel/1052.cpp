#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100005;
struct node {
    int addr;
    int key;
    int next;
    bool flag;
} list[MAXSIZE];

bool cmp(const node &a, const node &b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

int main() {
    for (int i = 0; i < MAXSIZE; i++)
        list[i].flag = false;
    int n, head, addr;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++) {
        scanf("%d", &addr);
        scanf("%d%d", &list[addr].key, &list[addr].next);
        list[addr].addr = addr;
    }
    int cnt = 0;
    for (int i = head; i != -1; i = list[i].next) {
        list[i].flag = true;
        cnt++;
    }
    if (cnt == 0)
        printf("0 -1");
    else {
        sort(list, list + MAXSIZE, cmp);
        printf("%d %05d\n", cnt, list[0].addr);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", list[i].addr, list[i].key);
            if (i < cnt - 1)
                printf("%05d\n", list[i + 1].addr);
            else
                printf("-1\n");
        }
    }
    return 0;
}