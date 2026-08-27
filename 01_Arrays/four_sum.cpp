/*
===========================================================
Problem: 4Sum
===========================================================

Given an integer array nums and an integer target, return
all unique quadruplets:

    [nums[i], nums[j], nums[k], nums[l]]

such that:

    nums[i] + nums[j] + nums[k] + nums[l] == target

Each quadruplet must contain four different indices.

-----------------------------------------------------------
Approach: Sorting + Two Pointers
-----------------------------------------------------------

1. Sort the array.
2. Fix the first element using index i.
3. Fix the second element using index j.
4. Use two pointers:
      k = j + 1
      l = n - 1
5. Calculate the sum of the four elements.
6. If sum < target, move k forward.
7. If sum > target, move l backward.
8. If sum == target:
      - Store the quadruplet.
      - Move both pointers.
      - Skip duplicate values.
9. Skip duplicate values for i and j to avoid
   duplicate quadruplets.

-----------------------------------------------------------
Complexity:
-----------------------------------------------------------

Time Complexity:  O(n^3)
Space Complexity: O(1) auxiliary space
                   (excluding the output vector)

-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array for the two-pointer approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int k = j + 1;
                int l = n - 1;

                while (k < l) {

                    long long sum = 1LL * nums[i]
                                  + nums[j]
                                  + nums[k]
                                  + nums[l];

                    if (sum == target) {

                        result.push_back({
                            nums[i],
                            nums[j],
                            nums[k],
                            nums[l]
                        });

                        k++;
                        l--;

                        // Skip duplicate third elements
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }

                        // Skip duplicate fourth elements
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return result;
    }
};
