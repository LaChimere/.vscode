#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
void printElems(const T& t)
{
    if (t.empty())
    {
        cout << "Empty" << endl;
        return;
    }
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i];
        if (i < t.size() - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums{1, 5, 3, 3, 5, 1, 1, 5};
    sort(nums.begin(), nums.end());	// 1 1 1 3 3 5 5 5
    for (const int& num : nums)
        cout << num << " ";
    cout << endl;
    auto low = lower_bound(nums.begin(), nums.end(), 3);
    auto up = upper_bound(nums.begin(), nums.end(), 3);

    nums.insert(low, 2);
    nums.insert(up, 4);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';

    return 0;
}