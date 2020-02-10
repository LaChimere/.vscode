#include "tools"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m, j = 0; j < n; i++, j++)
            nums1[i] = nums2[j];
        nums1.resize(m + n);
        sort(nums1.begin(), nums1.end());

        // 插入排序
        // for (int i = 0; i < n; i++) {
        //     int j;
        //     for (j = m + i - 1; j >= 0 && nums1[j] > nums2[i]; j--)
        //         nums1[j+1] = nums1[j];
        //     nums1[j+1] = nums2[i];
        // }
        // nums1.resize(m + n);
    }
};