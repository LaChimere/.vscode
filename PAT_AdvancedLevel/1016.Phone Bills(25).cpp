#include <bits/stdc++.h>
using namespace std;

int prices[25];
struct record {
    string name;
    int month, dd, hh, mm, time;
    bool status;
};

bool cmp(const record& a, const record& b) {
    if (a.name != b.name) return a.name < b.name;
    return a.time < b.time;
}

double billFromZero(const record& call) {
    double total = prices[call.hh] * call.mm + prices[24] * 60 * call.dd;
    for (int i = 0; i < call.hh; i++)
        total += prices[i] * 60;
    return total / 100.0;
}

int main() {
    int n;
    for (int i = 0; i < 24; i++) {
        cin >> prices[i];
        prices[24] += prices[i];
    }
    cin >> n;
    vector<record> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].dd, &records[i].hh, &records[i].mm);
        string flag;
        cin >> flag;
        records[i].status = (flag == "on-line");
        records[i].time = records[i].dd * 24 * 60 + records[i].hh * 60 + records[i].mm;
    }
    sort(records.begin(), records.end(), cmp);
    map<string, vector<record>> customers;
    for (int i = 1; i < n; i++) {
        if (records[i].name == records[i - 1].name && records[i - 1].status && !records[i].status) {
            customers[records[i - 1].name].push_back(records[i - 1]);
            customers[records[i].name].push_back(records[i]);
        }
    }
    for (const auto& it : customers) {
        vector<record> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i]) - billFromZero(temp[i - 1]);
            printf(
                "%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                temp[i - 1].dd, temp[i - 1].hh, temp[i - 1].mm,
                temp[i].dd, temp[i].hh, temp[i].mm,
                temp[i].time - temp[i - 1].time, t
            );
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}