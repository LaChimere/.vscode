#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <bitset>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> ans(queries.size());
    int sum = 0;
    for (int n : A)
        if (n % 2 == 0) sum += n;
    for (int i = 0; i < queries.size(); i++) {
        int val = queries[i][0], index = queries[i][1];
        int curAi = A[index] + val;
        if (curAi % 2 == 0) {
            sum += val;
            if (A[index] % 2 != 0) sum += A[index];
        } else if (A[index] % 2 == 0) sum -= A[index];
        ans[i] = sum;
        A[index] = curAi;
    }
    return ans;
}

int main() {
    vector<int> A({-10, 2, -4, 5, -3, 3});
    vector<vector<int>> queries({{-4, 2}, {9, 0}, {-8, 1}, {5, 4}, {1, 4}, {9, 0}});
    vector<int> res(sumEvenAfterQueries(A, queries));
    for (int n : res)
        cout << n << " ";
    return 0;
}