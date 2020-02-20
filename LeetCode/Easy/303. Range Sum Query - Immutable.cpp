#include "tools"
class NumArray {
private:
    int* sum;
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1];
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

// class NumArray {
// private:
//     vector<int> array;
// public:
//     NumArray(vector<int>& nums) {
//         array = nums;
//     }
    
//     int sumRange(int i, int j) {
//         int sum = 0;
//         int t = j < array.size() ? j : (array.size() - 1);
//         for (int k = i; k <= t; k++)
//             sum += array[k];
//         return sum;
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */