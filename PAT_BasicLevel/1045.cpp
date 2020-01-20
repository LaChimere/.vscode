#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int *num = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    vector<int> mainElem;
    for (int now = 0; now != n; now++) {
        int left = 0;
        int right = now + 1;
        for (; left != now; left++) {
            if (num[now] < num[left])
                break;
        }
        for (; right != n; right++) {
            if (num[now] > num[right])
                break;
        }
        if (left == now && right == n)
            mainElem.push_back(num[now]);
    }
    printf("%d\n", mainElem.size());
    sort(mainElem.begin(), mainElem.end());
    for (int i = 0; i < mainElem.size(); i++) {
        printf("%d", mainElem[i]);
        if (i < mainElem.size() - 1)
            printf(" ");
    }
    delete[] num;
    return 0;
}