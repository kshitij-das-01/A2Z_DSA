#include <bits/stdc++.h>
using namespace std;

// Solution 1
class Solution {
public:
    void reverse(vector<int> &arr, int l, int r)
    {
        while (l < r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++, r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n) k = k % n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

// 1 2 3 4 5 6 7

// 7 6 5 4 3 2 1
// 5 6 7 4 3 2 1
// 5 6 7 1 2 3 4

// 5 6 7 1 2 3 4