#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stuInfo {
    int id;
    int virtue;
    int talent;
};

bool cmp(const stuInfo a, const stuInfo b) {
    if (a.virtue + a.talent != b.virtue + b.talent)
        return a.virtue + a.talent > b.virtue + b.talent;
    else if (a.virtue != b.virtue)
        return a.virtue > b.virtue;
    else
        return a.id < b.id;
}

int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    vector<stuInfo> stu[4];
    stuInfo temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.id >> temp.virtue >> temp.talent;
        if (temp.virtue >= h) {
            if (temp.talent >= h)
                stu[0].push_back(temp);
            else if (temp.talent >= l)
                stu[1].push_back(temp);
        } else if (temp.virtue >= l) {
            if (temp.talent >= l && temp.virtue >= temp.talent)
                stu[2].push_back(temp);
            else if (temp.talent >= l && temp.virtue < temp.talent)
                stu[3].push_back(temp);
        }
    }
    int qualified = 0;
    for (int i = 0; i < 4; i++) {
        qualified += stu[i].size();
        if (stu[i].size() > 0)
            sort(stu[i].begin(), stu[i].end(), cmp);
    }
    printf("%d\n", qualified);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < stu[i].size(); j++)
            printf("%08d %d %d\n", stu[i][j].id, stu[i][j].virtue, stu[i][j].talent);
    }
    return 0;
}