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

struct info {
    string name, address;
    int age;
    info(string _name, string _address, int _age) : name(_name), address(_address), age(_age) {
        cout << "constructed" << endl;
    }
    info(info&& p) : name(move(p.name)), address(move(p.address)), age(p.age) {
        cout << "copied" << endl;
    }
};

int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 1);
    int res = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j]) dp[i] = max(1, dp[j] + 1);
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    vector<int> nums({1, 3, 6, 7, 9, 4, 10, 5, 6});
    cout << lengthOfLIS(nums);
    return 0;
}