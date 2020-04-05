// 测试结果为 WA, 待更正
#include <bits/stdc++.h>
using namespace std;

string readContent()
{
    string s, temp;
    cin >> temp;
    while (getline(cin, temp))
    {
        if (temp == "END")
            break;
        s += temp + "\n";
    }

    return s;
}

int judge(const string& _sol, const string& _ans)
{
    // 0: AC, -1: WA, 1: PE
    if (_sol == _ans)
        return 0;
    unordered_set<char> pes{' ', '\t', '\n'};
    string sol, ans;
    for (char c : _sol)
    {
        if (pes.count(c))
            continue;
        sol.push_back(c);
    }
    for (char c : _ans)
    {
        if (pes.count(c))
            continue;
        ans.push_back(c);
    }

    return sol == ans ? 1 : -1;
}

int main()
{
    int t;
    cin >> t;
    cin.get();

    while (t--)
    {
        string sol(readContent());
        string ans(readContent());
        switch (judge(sol, ans))
        {
            case 0:
                cout << "Accept\n";
                break;
            case 1:
                cout << "Presentation Error\n";
                break;
            case -1:
                cout << "Wrong Answer\n";
                break;
        }
    }

    return 0;
}
