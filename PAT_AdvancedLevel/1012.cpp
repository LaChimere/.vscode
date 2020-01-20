#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

struct stuInfo {
    int id, c_scores, m_scores, e_scores, a_scores;
    int c_rank, m_rank, e_rank;
    int best_rank;
    char best_subject;
};

bool cmp_a(const stuInfo a, const stuInfo b) {
    if (a.a_scores != b.a_scores)
        return a.a_scores > b.a_scores;
    else if (a.c_scores != b.c_scores)
        return a.c_scores > b.c_scores;
    else if (a.m_scores != b.m_scores)
        return a.m_scores > b.m_scores;
    else if (a.e_scores != b.e_scores)
        return a.e_scores > b.e_scores;
    else
        return a.id < b.id;
}

bool cmp_c(const stuInfo a, const stuInfo b) {
    if (a.c_scores != b.c_scores)
        return a.c_scores > b.c_scores;
    else if (a.a_scores != b.a_scores)
        return a.a_scores > b.a_scores;
    else if (a.m_scores != b.m_scores)
        return a.m_scores > b.m_scores;
    else if (a.e_scores != b.e_scores)
        return a.e_scores > b.e_scores;
    else
        return a.id < b.id;
}

bool cmp_m(const stuInfo a, const stuInfo b) {
    if (a.m_scores != b.m_scores)
        return a.m_scores > b.m_scores;
    else if (a.a_scores != b.a_scores)
        return a.a_scores > b.a_scores;
    else if (a.c_scores != b.c_scores)
        return a.c_scores > b.c_scores;
    else if (a.e_scores != b.e_scores)
        return a.e_scores > b.e_scores;
    else
        return a.id < b.id;
}

bool cmp_e(const stuInfo a, const stuInfo b) {
    if (a.e_scores != b.e_scores)
        return a.e_scores > b.e_scores;
    else if (a.a_scores != b.a_scores)
        return a.a_scores > b.a_scores;
    else if (a.c_scores != b.c_scores)
        return a.c_scores > b.c_scores;
    else if (a.m_scores != b.m_scores)
        return a.m_scores > b.m_scores;
    else
        return a.id < b.id;
}

void getRank(vector<stuInfo> &stu) {
    sort(stu.begin(), stu.end(), cmp_a);
    stu[0].best_rank = 1;
    stu[0].best_subject = 'A';
    for (int i = 1; i < stu.size(); i++) {
        stu[i].best_subject = 'A';
        if (stu[i].a_scores == stu[i - 1].a_scores)
            stu[i].best_rank = stu[i - 1].best_rank;
        else
            stu[i].best_rank = i + 1;
    }
    sort(stu.begin(), stu.end(), cmp_c);
    stu[0].c_rank = 1;
    if (stu[0].c_rank < stu[0].best_rank) {
        stu[0].best_rank = stu[0].c_rank;
        stu[0].best_subject = 'C';
    }
    for (int i = 1; i < stu.size(); i++) {
        if (stu[i].c_scores == stu[i - 1].c_scores)
            stu[i].c_rank = stu[i - 1].c_rank;
        else
            stu[i].c_rank = i + 1;
        if (stu[i].c_rank < stu[i].best_rank) {
            stu[i].best_rank = stu[i].c_rank;
            stu[i].best_subject = 'C';
        }
    }
    sort(stu.begin(), stu.end(), cmp_m);
    stu[0].m_rank = 1;
    if (stu[0].m_rank < stu[0].best_rank) {
        stu[0].best_rank = stu[0].m_rank;
        stu[0].best_subject = 'M';
    }
    for (int i = 1; i < stu.size(); i++) {
        if (stu[i].m_scores == stu[i - 1].m_scores)
            stu[i].m_rank = stu[i - 1].m_rank;
        else
            stu[i].m_rank = i + 1;
        if (stu[i].m_rank < stu[i].best_rank) {
            stu[i].best_rank = stu[i].m_rank;
            stu[i].best_subject = 'M';
        }
    }
    sort(stu.begin(), stu.end(), cmp_e);
    stu[0].e_rank = 1;
    if (stu[0].e_rank < stu[0].best_rank) {
        stu[0].best_rank = stu[0].e_rank;
        stu[0].best_subject = 'E';
    }
    for (int i = 1; i < stu.size(); i++) {
        if (stu[i].e_scores == stu[i - 1].e_scores)
            stu[i].e_rank = stu[i - 1].e_rank;
        else
            stu[i].e_rank = i + 1;
        if (stu[i].e_rank < stu[i].best_rank) {
            stu[i].best_rank = stu[i].e_rank;
            stu[i].best_subject = 'E';
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<stuInfo> stu;
    stuInfo temp;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &temp.id, &temp.c_scores, &temp.m_scores, &temp.e_scores);
        temp.a_scores = (int)round((temp.c_scores + temp.m_scores + temp.e_scores) / 3.0);
        stu.push_back(temp);
    }
    getRank(stu);
    unordered_map<int, stuInfo> stuList;
    for (int i = 0; i < n; i++)
        stuList[stu[i].id] = stu[i];
    while (m--) {
        scanf("%d", &temp.id);
        if (stuList.find(temp.id) != stuList.end())
            printf("%d %c\n", stuList.find(temp.id)->second.best_rank, stuList.find(temp.id)->second.best_subject);
        else
            printf("N/A\n");
    }
    return 0;
}