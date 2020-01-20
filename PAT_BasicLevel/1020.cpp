#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mooncake {
    double store;
    double sell;
    double price;
};

bool cmp(const mooncake a, const mooncake b) {
    return a.price > b.price;
}

int main() {
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    vector<mooncake> m(n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &m[i].store);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &m[i].sell);
        m[i].price = m[i].sell / m[i].store;
    }
    sort(m.begin(), m.end(), cmp);
    double w = 0.0;
    for (int i = 0; i < n; i++) {
        if (m[i].store <= d) {
            w += m[i].sell;
            d -= m[i].store;
        } else if (m[i].store > d) {
            w += m[i].price * d;
            break;
        }
    }
    printf("%.2f", w);
    return 0;
}