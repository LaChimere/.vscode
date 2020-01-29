#include <iostream>
#include <unordered_map>
using namespace std;

struct node {
    char data;
    int next;
};

unordered_map<int, node> words;

int main() {
    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    int addr;
    while (n--)
        cin >> addr >> words[addr].data >> words[addr].next;
    int len1 = 0, len2 = 0;
    int p1 = head1, p2 = head2;
    while (p1 != -1) {
        len1++;
        p1 = words[p1].next;
    }
    while (p2 != -1) {
        len2++;
        p2 = words[p2].next;
    }
    p1 = head1, p2 = head2;
    int d;
    if (len1 > len2) {
        d = len1 - len2;
        for (int i = 0; i < d; i++)
            p1 = words[p1].next;
    } else {
        d = len2 - len1;
        for (int i = 0; i < d; i++)
            p2 = words[p2].next;
    }
    while (p1 != -1 && p2 != -1) {
        if (words[p1].data == words[p2].data)
            break;
        p1 = words[p1].next;
        p2 = words[p2].next;
    }
    cout << p1;
    return 0;
}