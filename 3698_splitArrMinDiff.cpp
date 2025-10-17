/*
Split Array with Increasing–Decreasing Check

Overview
This C++ program finds the minimum absolute difference between the sums of two parts of an array after splitting it such that:
- The left part is **strictly increasing**.
- The right part is **strictly decreasing**.

If no valid split exists, it returns `-1`.

How It Works
- Iterates through the array.
- Calculates left and right sums.
- Checks decreasing order on the right side.
- Keeps track of the smallest valid split difference.

Complexity
- **Time:** O(n²)
- **Space:** O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check_dec(vector<int>& arr, int low, int high) {
        for (int i = low; i < high; i++) {
            if (arr[i] <= arr[i + 1]) return false;
        }
        return true;
    }

public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long split = LLONG_MAX;
        long long rightsum = 0, leftsum = 0;

        for (int i = 0; i < n; i++) rightsum += nums[i];
        int i = 0;

        while (i < n - 1) {
            leftsum += nums[i];
            rightsum -= nums[i];

            if (split > abs(leftsum - rightsum)) {
                bool right = check_dec(nums, i + 1, n - 1);
                if (right) split = abs(leftsum - rightsum);
            }

            if (nums[i] >= nums[i + 1]) break;
            i++;
        }

        if (split == LLONG_MAX) return -1;
        return split;
    }
};