// WA, 待更正
#include <bits/stdc++.h>
using namespace std;

bool judge(int num)
{
    // num has 5 digits, which might include prefix-0
    // num >= 01234 && num <= 98765, if num < 10000, digits.insert(0)
    if (num < 1234 || num > 98765)
        return false;

    unordered_set<int> digits;
    if (num < 10000)
        digits.insert(0);
    while (num)
    {
        digits.insert(num % 10);
        num /= 10;
    }
    return digits.size() == 5;
}

bool judge(int num1, int num2)
{
    if (num1 < 1234 || num1 > 98765 || num2 < 1234 || num2 > 98765)
        return false;

    unordered_set<int> digits;
    if (num1 < 10000 || num2 < 10000)
        digits.insert(0);
    while (num1)
    {
        digits.insert(num1 % 10);
        num1 /= 10;
    }
    while (num2)
    {
        digits.insert(num2 % 10);
        num2 /= 10;
    }
    return digits.size() == 10;
}

set<int> checkNums;

int main()
{
    int n, pre = -1;

    for (int num = 1234; num <= 98765; num++)
    {
        if (judge(num))
            checkNums.insert(num);
    }

    while (cin >> n)
    {
        if (n == 0)
            break;

        if (pre != -1)
            cout << endl;
        pre = n;

        bool found = false;
        for (auto denominator : checkNums)
        {
            int numerator = n * denominator;
            if (!checkNums.count(numerator))
                continue;
            if (judge(numerator, denominator))
            {
                found = true;
                printf("%05d / %05d = %d\n", numerator, denominator, n);
            }
        }

        if (!found)
            cout << "There are no solutions for " << n << endl;
    }

    return 0;
}
