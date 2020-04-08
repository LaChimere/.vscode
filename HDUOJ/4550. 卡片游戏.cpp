#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string cards, res;
        cin >> cards;

        int minPos;
        char minChar = '9' + 1;

        for (int i = cards.length() - 1; i >= 0; i--)
        {
            if (cards[i] != '0' && cards[i] < minChar)
            {
                minChar = cards[i];
                minPos = i;
            }
        }

        res.push_back(*cards.begin());
        for (int i = 1; i <= minPos; i++)
        {
            if (i < minPos)
            {
                if (cards[i] > res[0])
                    res.push_back(cards[i]);
                else
                    res.insert(res.begin(), cards[i]);
            }
            else
                res.insert(res.begin(), cards[i]);
        }
        res += cards.substr(minPos + 1);

        cout << res << endl;
    }

    return 0;
}