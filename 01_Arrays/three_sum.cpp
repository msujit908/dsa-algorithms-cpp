/*
===========================================================
Problem: 3Sum
===========================================================

Given an integer array nums, return all unique triplets
[nums[i], nums[j], nums[k]] such that:

    nums[i] + nums[j] + nums[k] == 0

Constraints:
- Each triplet must contain three different indices.
- The solution must not contain duplicate triplets.

-----------------------------------------------------------
Approach: Sorting + Two Pointers
-----------------------------------------------------------

1. Sort the array.
2. Fix the first element using index i.
3. Use two pointers:
      j = i + 1
      k = n - 1
4. Calculate the sum of nums[i], nums[j], and nums[k].
5. If sum < 0, move j forward.
6. If sum > 0, move k backward.
7. If sum == 0, store the triplet and move both pointers.
8. Skip duplicate values to avoid duplicate triplets.

-----------------------------------------------------------
Complexity:
-----------------------------------------------------------

Time Complexity:  O(n^2)
Space Complexity: O(1) auxiliary space
                   (excluding the output vector)

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array for two-pointer approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                long long sum = 1LL * nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    result.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    // Skip duplicate second elements
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate third elements
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return result;
    }
};
