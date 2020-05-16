#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        auto it = target.begin();
        vector<string> res;
        for (int num = 1; num <= n; num++)
        {
            if (it == target.end())
                break;
            
            if (num != *it)
            {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
            else
            {
                res.emplace_back("Push");
                it++;
            }
        }
        
        return res;
    }
};