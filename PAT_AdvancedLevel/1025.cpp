#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stuInfo {
    string regitNum;
    int score;
    int final_rank;
    int local_rank;
    int local_num;
};

bool cmp(const stuInfo a, const stuInfo b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.regitNum < b.regitNum;
}

int main() {
    int n, k;
    cin >> n;
    vector<stuInfo> finalList;
    for (int i = 0; i < n; i++) {
        cin >> k;
        vector<stuInfo> stu(k);
        for (int j = 0; j < k; j++) {
            cin >> stu[j].regitNum >> stu[j].score;
            stu[j].local_num = i + 1;
        }
        sort(stu.begin(), stu.end(), cmp);
        stu[0].local_rank = 1;
        finalList.push_back(stu[0]);
        for (int j = 1; j < k; j++) {
            if (stu[j].score == stu[j - 1].score)
                stu[j].local_rank = stu[j - 1].local_rank;
            else
                stu[j].local_rank = j + 1;
            finalList.push_back(stu[j]);
        }
    }
    sort(finalList.begin(), finalList.end(), cmp);
    finalList[0].final_rank = 1;
    cout << finalList.size() << endl;
    cout << finalList[0].regitNum << " " << finalList[0].final_rank << " " << finalList[0].local_num << " " << finalList[0].local_rank << endl;
    for (int i = 1; i < finalList.size(); i++) {
        if (finalList[i].score == finalList[i - 1].score)
            finalList[i].final_rank = finalList[i - 1].final_rank;
        else
            finalList[i].final_rank = i + 1;
        cout << finalList[i].regitNum << " " << finalList[i].final_rank << " " << finalList[i].local_num << " " << finalList[i].local_rank << endl;
    }
    return 0;
}